import logging
import sys
import argparse
import datetime
import os
from socketserver import BaseRequestHandler
import socket

from .network.mo_server import MOServiceServer
from .messages.mobile_originated import MOMessage

# нужны переменные окружения MAVLINK10 и MAVLINK_DIALECT=zikush
from pymavlink.mavutil import mavlink_connection, mavudp, mavlogfile
from pymavlink.dialects.v10.zikush import MAVLink
_log = logging.getLogger(__name__)


def build_req_handler_cls(mav_handler):

    class ReqHandler(BaseRequestHandler):
        def handle(self):
            msg = self.request

            hdr = msg.header
            if not hdr:
                _log.warning("no header")
            loc = msg.loc_info
            if not loc:
                _log.warning("no location info present")

            # Создаем мавы
            main_mav = MAVLink(None, srcSystem=1)

            # Делаем мета сообщение
            meta_msg = main_mav.zikush_iridium_meta_encode(
                mtmsn=hdr.mtmsn if hdr else 0,
                momsn=hdr.momsn if hdr else 0,
                session_status=hdr.session_status if hdr else 0,
                imei=hdr.imei.encode("utf-8") if hdr else [],
                time_of_session=int(hdr.time_of_session.timestamp()) if hdr else 0,
                lat=loc.lat if loc else 0,
                lon=loc.lon if loc else 0,
            )

            # Рассылаем мета сообщение по мавам
            mav_handler(meta_msg)

            # Парсим пейлоад
            pay = msg.payload
            if not pay:
                _log.warning("no payload present")
            else:
                for char in msg.payload.raw_payload:
                    msg = main_mav.parse_char(char)
                    if msg:
                        _log.info("got mav message: %s" % msg)
                        mav_handler(msg)

    return ReqHandler


# noinspection PyBroadException
def main(listen_addr, relay_addr, log_dir: str):

    os.makedirs(log_dir, exist_ok=True)
    blog_fpath = os.path.join(
        log_dir,
        "iridium-log-%s.blog" % datetime.datetime.utcnow().strftime("%Y%m%dT%H%M%S")
    )
    mlog_fpath = os.path.join(
        log_dir,
        "iridium-log-%s.mlog" % datetime.datetime.utcnow().strftime("%Y%m%dT%H%M%S")
    )

    with open(blog_fpath, mode="wb") as blog_stream:

        relay_mav = mavudp("%s:%d" % relay_addr, input=False)
        log_mav = mavlogfile(mlog_fpath, write=True, notimestamps=True)

        def relay_mav_msg(msg):
            relay_mav.mav.send(msg)
            log_mav.mav.send(msg)

        RequestHandler = build_req_handler_cls(relay_mav_msg)

        server = MOServiceServer(
            server_address=listen_addr,
            request_handler_cls=RequestHandler,
            bind_and_activate=True,
            send_ack=False,
            blog_stream=blog_stream,
        )

        rc = 0

        try:
            _log.info("starting server")
            server.serve_forever()

        except KeyboardInterrupt:
            _log.info("server stopped by ctrl+c")

        except Exception:
            rc = 1
            _log.exception("an error occured")

        finally:
            server.shutdown()

        return rc


def main_exec():
    FORMAT = "%(asctime)s - %(levelname)s - %(message)s"

    logging.basicConfig(level=logging.DEBUG, stream=sys.stdout, format=FORMAT)

    parser = argparse.ArgumentParser("devutil SBD receiver", add_help=True)

    parser.add_argument("--listen-port", action="store", dest="port", nargs="?", type=int,
                        default="1221")
    parser.add_argument("--listen-iface", action="store", dest="iface", nargs="?", type=str,
                        default="0.0.0.0")
    parser.add_argument("--log-dir", action="store", dest="log_dir", nargs="?", type=str,
                        default="logs")
    parser.add_argument("--relay-addr", action="store", dest="relay_addr", nargs="?", type=str,
                        required=True)
    parser.add_argument("--relay-port", action="store", dest="relay_port", nargs="?", type=int,
                        required=True)

    args = parser.parse_args(sys.argv[1:])

    listen_addr = args.iface, args.port
    relay_addr = args.relay_addr, args.relay_port
    log_dir = args.log_dir

    return main(listen_addr, relay_addr, log_dir)


if __name__ == "__main__":
    exit(main_exec())
