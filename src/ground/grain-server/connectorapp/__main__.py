import sys
import logging
import time
import json
import os
from datetime import datetime

from pymavlink import mavutil
from pymavlink.dialects.v20.zikush import MAVLink_heartbeat_message, MAVLink_scaled_pressure_message, \
    MAVLink_scaled_pressure2_message, MAVLink_zikush_humidity_message

from common.definitions import ZSET_NAME_SCALED_PRESSURE
from .redis_store import redis_store

from ..common.config import get_config
from ..common.definitions import ZSET_NAME_SCALED_PRESSURE, ZSET_NAME_SCALED_PRESSURE2, ZSET_NAME_SPECTRUM


from .spectrum import SpectrumAggregator, SpectrumAcceptor, PictureSaver

_log = logging.getLogger(__name__)
_config = get_config()
_putback = _config["MAV_PLOT_DATA_PBACK"]


def update_zset(set_name, message):
    p = redis_store.pipeline()

    # кастуем соообщение в json
    # Добавим в сообщение метку времени для уникальности, так как в zrange можно добавлять только уникальные метки
    # Так же, по времени будем строить ось x наших данных в виде "стоимости" элемента zset-а
    timestamp = int(round(time.time() * 1000))

    dmsg = message.to_dict()
    jmsg = json.dumps(dmsg)

    p.zadd(set_name, timestamp, jmsg)
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


def main(argv):
    logging.basicConfig(stream=sys.stdout, level=_config["MAV_LOG_LEVEL"])

    _log.info("Запускаюсь. Слушаю url: %s" % _config["MAV_LISTEN_URL"])
    connection = mavutil.mavlink_connection(_config["MAV_LISTEN_URL"])
    mav = connection

    now = datetime.utcnow().isoformat()
    logfile = "/opt/logs/%s_mavlink_app.mav" % now
    mav.setup_logfile(logfile)
    _log.error("mavlog setted up %s" % logfile)

    connectorapp_path = os.path.dirname(os.path.abspath(__file__)) # Path to ...../grain_server/connectorapp
    grain_path = os.path.dirname(connectorapp_path)
    filename_template = grain_path + '/webapp/tmp/img/%d.png'

    spectrum_aggregator = SpectrumAggregator(spectrum_acceptor=SpectrumRedisSaver(),
                                            picture_acceptor=PictureSaver(filename_template=filename_template))

    while True:
        msg = mav.recv_match(blocking=True)
        _log.debug("got message %s", msg)

        if isinstance(msg, MAVLink_scaled_pressure_message):
            """ Temperature and pressure from BME280 """
            update_zset(ZSET_NAME_SCALED_PRESSURE, msg)

        elif isinstance(msg, MAVLink_scaled_pressure2_message):
            """ External temperature and pressure """
            update_zset(ZSET_NAME_SCALED_PRESSURE2, msg)

        elif isinstance(msg, MAVLink_zikush_humidity_message):
            """ External temperature and pressure """
            update_zset(ZSET_NAME_SCALED_PRESSURE2, msg)

        '''elif isinstance(msg, MAVLink_picture_header_message) \
            or isinstance(msg, MAVLink_intensity_header_message) \
            or isinstance(msg, MAVLink_encapsulated_data_message) \
            or isinstance(msg, MAVLink_intensity_encapsulated_data_message):
            """ Сообщения, относящиеся к спектру """
            spectrum_aggregator.accept_message(msg)'''


if __name__ == "__main__":
    exit(main([]))
