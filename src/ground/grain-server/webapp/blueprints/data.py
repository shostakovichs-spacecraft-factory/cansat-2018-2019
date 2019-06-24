import time
import json
import os
import random

from flask import Blueprint, jsonify, request, current_app, send_file

from ...common import definitions as common_definitions
from ..redis_store import redis_store


def now():
    return float(round(time.time()*1000))


def viewlimit(plotname, timebase=now()):
    return timebase - current_app.config["%s_PLOT_SCOPE_MS" % plotname].total_seconds()*1000


data = Blueprint('data', __name__, url_prefix="/data")


@data.route("/plot_data")
def plot_data():
    chart_name = request.args.get("chartName")

    if chart_name == "acc":
        return _get_acc_data()
    elif chart_name == "gyro":
        return _get_gyro_data()
    elif chart_name == "temperature":
        return _get_temperature_data()
    elif chart_name == "pressure":
        return _get_pressure_data()



@data.route("/map_data")
def map_data():
    # Достаем элементы
    time = now()
    latest_update_time = float(request.args.get("latestUpdateTime"))
    latest_update_time = max(latest_update_time, viewlimit("MAP", time))

    zsetname = common_definitions.ZSET_NAME_MAP
    elems = redis_store.zrangebyscore(zsetname, latest_update_time, time, withscores=True, score_cast_func=int)

    data = []
    for e in elems:
        value, score = e
        value = json.loads(value.decode("utf-8"))
        data.append({
            'time_usec': value['time_usec'],
            'fix_type': value['fix_type'],
            'lat': value['lat'] / (10.0 ** 7),
            'lon': value['lon'] / (10.0 ** 7),
            'alt': value['alt'] / 1000,
            'servertime': score
        })

    return jsonify(data)


@data.route("/gl_data")
def gl_data():
    # Достаем последний элемент
    zsetname = common_definitions.ZSET_NAME_ATTITUDE
    elems = redis_store.zrange(zsetname, -1, -1, withscores=True, score_cast_func=int)

    data = []
    for e in elems:
        value, score = e
        value = json.loads(value.decode("utf-8"))
        data.append({
            'data': [value['q2'], value['q3'], value['q4'], value['q1']],
            'servertime': score
        })

    if not data:
        data.append({
            'data': [1, 0, 0, 0],
            'servertime': -1
        })

    return jsonify(data)


@data.route("/spectrum_data")
def spectrum_data():
    # Достаем последний элемент
    zsetname = common_definitions.ZSET_NAME_SPECTRUM

    try:
        spectrum, score = redis_store.zrange(zsetname, -1, -1, withscores=True, score_cast_func=int) [0]
        spectrum = json.loads(spectrum.decode("utf-8"))

        data = {'data': [], 'identifier': spectrum['identifier']}

        for i, dot in enumerate(spectrum['data']):
            data['data'].append({
                'x': i,
                'y': dot
            })

        data['timestamp'] = score

    except IndexError:
        data = {'data': [], 'identifier': -1}

    return jsonify(data)


@data.route("/spectrum_img")
def spectrum_img():
    identifier = int(request.args.get("identifier"))

    if identifier == -1:
        return send_file('static/staytuned.jpg')

    return send_file('tmp/img/%d.png' % identifier)


@data.route("/background")
def background_img():
    backgrounds_folder = os.path.join(current_app.root_path, "static/backgrounds/")
    background = random.choice(os.listdir(backgrounds_folder))

    responce = send_file("static/backgrounds/" + background)
    responce.headers._list[3] = ('Cache-Control','no-cache')
    return responce

@data.route("/status")
def status():
    # Достаем последний элемент
    zsetname = common_definitions.ZSET_NAME_STATE

    try:
        status, score = redis_store.zrange(zsetname, -1, -1, withscores=True, score_cast_func=int) [0]
        status = json.loads(status.decode("utf-8"))

    except IndexError:
        status = {"status": -1}

    return jsonify(status)


def _get_data_abstract(plotname, yvalue_name, time=now()):
    """ Преобразует набор "мавлинкоджсоновых элементов в набор элементов точек для графика
    Элементы оси Y выбираются по указанному ключу """

    # Достаем элементы
    latest_update_time = float(request.args.get("latestUpdateTime"))
    latest_update_time = max(latest_update_time, viewlimit(plotname, time))

    zsetname = getattr(common_definitions, "ZSET_NAME_%s" % plotname)
    elems = redis_store.zrangebyscore(zsetname, latest_update_time, time, withscores=True, score_cast_func=int)

    data = []
    for e in elems:
        value, score = e
        value = json.loads(value.decode("utf-8"))
        data.append({
            "x": value["time_boot_ms"] / 1000.0,  # будем показывать секунды, считаем что бортовое время в мс
            "y": value[yvalue_name],
            "servertime": score
        })

    return data


def _get_acc_data():
    """ Датасет для графика акселерометра """
    time = now()
    datax, datay, dataz = [_get_data_abstract("IMU", x, time) for x in ("xacc", "yacc", "zacc")]

    for x, y, z in zip(datax, datay, dataz):
        x["y"] /= 1000.0
        y["y"] /= 1000.0
        z["y"] /= 1000.0

    latestUpdateTime = request.args.get("latestUpdateTime")
    if len(datax) > 0:
        latestUpdateTime = datax[-1]["servertime"]

    data = {
        "datas": [datax, datay, dataz],
        "latestUpdateTime": latestUpdateTime,
        "viewlimit": viewlimit("IMU", time)
    }

    return jsonify(data)


def _get_gyro_data():
    """ Датасет для графика гироскопа """
    time = now()
    datax, datay, dataz = [_get_data_abstract("IMU", x, time) for x in ("xgyro", "ygyro", "zgyro")]

    latestUpdateTime = request.args.get("latestUpdateTime")
    if len(datax) > 0:
        latestUpdateTime = datax[-1]["servertime"]

    for x, y, z in zip(datax, datay, dataz):
        x["y"] /= 1000.0
        y["y"] /= 1000.0
        z["y"] /= 1000.0

    data = {
        "datas": [datax, datay, dataz],
        "latestUpdateTime": latestUpdateTime,
        "viewlimit": viewlimit("IMU", time)
    }

    return jsonify(data)


def _get_temperature_data():
    time = now()
    temperature_int = _get_data_abstract("PRESSTEMP_INTERNAL", "temperature", time)
    temperature_ext = _get_data_abstract("PRESSTEMP_EXTERNAL", "temperature", time)

    latestUpdateTime = request.args.get("latestUpdateTime")
    if len(temperature_int) > 0:
        latestUpdateTime = temperature_int[-1]["servertime"]


    for record in temperature_int:
        record["y"] /= 100.0

    data = {
        "datas": [temperature_int, temperature_ext],
        "latestUpdateTime": latestUpdateTime,
        "viewlimit": viewlimit("PRESSTEMP", time)
    }

    return jsonify(data)

def _get_pressure_data():
    time = now()
    pressure_int = _get_data_abstract("PRESSTEMP_INTERNAL", "press_abs", time)
    pressure_ext = _get_data_abstract("PRESSTEMP_EXTERNAL", "press_abs", time)

    latestUpdateTime = request.args.get("latestUpdateTime")
    if len(pressure_int) > 0:
        latestUpdateTime = pressure_int[-1]["servertime"]

    data = {
        "datas": [pressure_int, pressure_ext],
        "latestUpdateTime": latestUpdateTime,
        "viewlimit": viewlimit("PRESSTEMP", time)
    }

    return jsonify(data)
