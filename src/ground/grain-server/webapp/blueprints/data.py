import time
import json
import os
import random

from flask import Blueprint, render_template, abort, jsonify, request, current_app, send_file
from jinja2 import TemplateNotFound

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
    elif chart_name == "temperature-bmp":
        return _get_temperature_bmp_data()
    elif chart_name == "temperature-am":
        return _get_temperature_am_data()
    elif chart_name == "pressure":
        return _get_pressure_data()
    elif chart_name == "distance":
        return _get_distance_data()
    elif chart_name == "luminosity":
        return _get_luminosity_data()
    elif chart_name == "humidity":
        return _get_humidity_data()



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

    return jsonify(data)


@data.route("/spectrum_data")
def spectrum_data():
    # Достаем последний элемент
    zsetname = common_definitions.ZSET_NAME_SPECTRUM
    spectrum, score = redis_store.zrange(zsetname, -1, -1, withscores=True, score_cast_func=int) [0]

    spectrum = json.loads(spectrum.decode("utf-8"))

    data = {'data': [], 'identifier': spectrum['identifier']}

    for i, dot in enumerate(spectrum['data']):
        data['data'].append({
            'x': i,
            'y': dot
        })

    data['timestamp'] = score

    return jsonify(data)


@data.route("/spectrum_img")
def spectrum_img():
    identifier = int(request.args.get("identifier"))

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
    zsetname = common_definitions.ZSET_NAME_STATUS
    status, score = redis_store.zrange(zsetname, -1, -1, withscores=True, score_cast_func=int) [0]

    status = json.loads(status.decode("utf-8"))

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


def _get_temperature_bmp_data():
    time = now()
    temperature_bmp = _get_data_abstract("PRESSURE", "temperature", time)


    latestUpdateTime = request.args.get("latestUpdateTime")
    if len(temperature_bmp) > 0:
        latestUpdateTime = temperature_bmp[-1]["servertime"]


    for record in temperature_bmp:
        record["y"] /= 100.0

    data = {
        "datas": [temperature_bmp],
        "latestUpdateTime": latestUpdateTime,
        "viewlimit": viewlimit("PRESSURE", time)
    }

    return jsonify(data)

def _get_temperature_am_data():
    time = now()
    temperature_am = _get_data_abstract("HUMIDITY", "temperature", time)


    latestUpdateTime = request.args.get("latestUpdateTime")
    if len(temperature_am) > 0:
        latestUpdateTime = temperature_am[-1]["servertime"]


    for record in temperature_am:
        record["y"] /= 10.0

    data = {
        "datas": [temperature_am],
        "latestUpdateTime": latestUpdateTime,
        "viewlimit": viewlimit("HUMIDITY", time)
    }

    return jsonify(data)

def _get_pressure_data():
    time = now()
    pressure = _get_data_abstract("PRESSURE", "press_abs", time)

    latestUpdateTime = request.args.get("latestUpdateTime")
    if len(pressure) > 0:
        latestUpdateTime = pressure[-1]["servertime"]

    data = {
        "datas": [pressure],
        "latestUpdateTime": latestUpdateTime,
        "viewlimit": viewlimit("PRESSURE", time)
    }

    return jsonify(data)

def _get_distance_data():
    time = now()
    distance = _get_data_abstract("DISTANCE", "distance", time)

    latestUpdateTime = request.args.get("latestUpdateTime")
    if len(distance) > 0:
        latestUpdateTime = distance[-1]["servertime"]

    data = {
        "datas": [distance],
        "latestUpdateTime": latestUpdateTime,
        "viewlimit": viewlimit("DISTANCE", time)
    }

    return jsonify(data)

def _get_luminosity_data():
    time = now()
    luminosity = _get_data_abstract("LUMINOSITY", "luminosity", time)

    latestUpdateTime = request.args.get("latestUpdateTime")
    if len(luminosity) > 0:
        latestUpdateTime = luminosity[-1]["servertime"]

    data = {
        "datas": [luminosity],
        "latestUpdateTime": latestUpdateTime,
        "viewlimit": viewlimit("LUMINOSITY", time)
    }

    return jsonify(data)

def _get_humidity_data():
    time = now()
    humidity = _get_data_abstract("HUMIDITY", "humidity", time)

    latestUpdateTime = request.args.get("latestUpdateTime")
    if len(humidity) > 0:
        latestUpdateTime = humidity[-1]["servertime"]

    for record in humidity:
        record['y'] /= 10.0

    data = {
        "datas": [humidity],
        "latestUpdateTime": latestUpdateTime,
        "viewlimit": viewlimit("HUMIDITY", time)
    }

    return jsonify(data)
