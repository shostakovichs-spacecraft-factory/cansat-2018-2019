import sys
import logging
import time
import json
import os
from datetime import datetime

from pymavlink import mavutil
from pymavlink.dialects.v20.zikush import MAVLink_heartbeat_message, MAVLink_scaled_pressure_message, \
    MAVLink_scaled_pressure2_message, MAVLink_encapsulated_data_message,\
    MAVLink_zikush_state_message, MAVLink_zikush_power_state_message, MAVLink_zikush_sunsensor_message, \
    MAVLink_zikush_humidity_message, MAVLink_zikush_picture_header_message, MAVLink_zikush_spectrum_intensity_header_message, \
    MAVLink_zikush_spectrum_intensity_encapsulated_data_message

from .redis_store import redis_store

from ..common.config import get_config
from ..common.definitions import ZSET_NAME_PRESSTEMP_INTERNAL, ZSET_NAME_PRESSTEMP_EXTERNAL, ZSET_NAME_SPECTRUM, ZSET_NAME_MAP, \
    ZSET_NAME_ATTITUDE, ZSET_NAME_SPECTRUM, ZSET_NAME_SUNSENSOR, ZSET_NAME_HUMIDITY, ZSET_NAME_POWER_STATE, ZSET_NAME_STATE\



from .streams_sink import StreamAggregator, SpectrumAcceptor, PictureSaver

_log = logging.getLogger(__name__)
_config = get_config()
_putback = _config["CONN_PLOT_DATA_PBACK"]


def update_zset(set_name, message):
    p = redis_store.pipeline()

    # кастуем соообщение в json
    # Добавим в сообщение метку времени для уникальности, так как в zrange можно добавлять только уникальные метки
    # Так же, по времени будем строить ось x наших данных в виде "стоимости" элемента zset-а
    timestamp = int(round(time.time() * 1000))

    dmsg = message.to_dict()
    jmsg = json.dumps(dmsg)

    p.zadd(set_name, {jmsg: timestamp} )
    p.execute()

    # Теперь удаляем из zrange все что старше, чем позволяет наши pback из конфига
    deadline = timestamp - _putback.total_seconds() * 1000
    p.zremrangebyscore(set_name, 0, deadline)
    p.execute()


class SpectrumRedisSaver(SpectrumAcceptor):
    def __init__(self):
        super().__init__()

    def accept(self, data, identifier):
        dictioned = {'identifier': identifier, 'data': data}

        class Dummy:
            def to_dict(self): return dictioned

        update_zset(ZSET_NAME_SPECTRUM, Dummy())


def HeartbeatHandler(msg):
    pass


def main(argv):
    logging.basicConfig(stream=sys.stdout, level=_config["CONN_LOG_LEVEL"])

    _log.info("Запускаюсь. Слушаю url: %s" % _config["CONN_LISTEN_URL"])
    connection = mavutil.mavlink_connection(_config["CONN_LISTEN_URL"])
    mav = connection

    now = datetime.utcnow().isoformat()
    logfile = "/opt/logs/%s_mavlink_app.mav" % now
    try:
        mav.setup_logfile(logfile)
    except FileNotFoundError:
        print("Cannot setup logfile", logfile)
    else:
        _log.error("mavlog setted up %s" % logfile)

    connectorapp_path = os.path.dirname(os.path.abspath(__file__)) # Path to ...../grain_server/connectorapp
    grain_path = os.path.dirname(connectorapp_path)
    spectrumpicture_filename_template = grain_path + '/webapp/tmp/img/spectrum/%d.png'
    nadirpicture_filename_template = grain_path + '/webapp/tmp/img/nadir/%d.png'
    zenithpicture_filename_template = grain_path + '/webapp/tmp/img/zenith/%d.png'

    stream_aggregator = StreamAggregator(spectrum_acceptor=SpectrumRedisSaver(),
                        picture_acceptor_spectrum=PictureSaver(filename_template=spectrumpicture_filename_template),
                        picture_acceptor_nadir = PictureSaver(filename_template=nadirpicture_filename_template),
                        picture_acceptor_zenith = PictureSaver(filename_template=zenithpicture_filename_template)),

    while True:
        msg = mav.recv_match(blocking=True)
        _log.debug("got message %s", msg)

        if isinstance(msg, MAVLink_heartbeat_message):
            HeartbeatHandler(msg)

        elif isinstance(msg, MAVLink_scaled_pressure_message):
            """ Temperature and pressure from BME280 """
            update_zset(ZSET_NAME_PRESSTEMP_INTERNAL, msg)

        elif isinstance(msg, MAVLink_scaled_pressure2_message):
            """ External temperature and pressure """
            update_zset(ZSET_NAME_PRESSTEMP_EXTERNAL, msg)

        elif isinstance(msg, MAVLink_zikush_humidity_message):
            """ Humidity """
            update_zset(ZSET_NAME_HUMIDITY, msg)

        elif isinstance(msg, MAVLink_zikush_state_message):
            """ Probe state """
            update_zset(ZSET_NAME_STATE, msg)

        elif isinstance(msg, MAVLink_zikush_sunsensor_message):
            """ Sunsensor """
            update_zset(ZSET_NAME_SUNSENSOR, msg)

        elif isinstance(msg, MAVLink_zikush_power_state_message):
            """ Power buses state """
            update_zset(ZSET_NAME_POWER_STATE, msg)

        elif isinstance(msg, MAVLink_zikush_picture_header_message) \
            or isinstance(msg, MAVLink_zikush_spectrum_intensity_header_message) \
            or isinstance(msg, MAVLink_encapsulated_data_message) \
            or isinstance(msg, MAVLink_zikush_spectrum_intensity_encapsulated_data_message):
            """ Handling multiframe transfers """
            stream_aggregator.accept_message(msg)


if __name__ == "__main__":
    exit(main([]))
