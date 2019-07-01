import typing
import logging
import sys
import argparse
from socketserver import BaseRequestHandler

from ..network.mo_server import MOServiceServer
from ..messages.mobile_originated import MOMessage

_log = logging.getLogger(__name__)


class ReqHandler(BaseRequestHandler):
    def handle(self):
        msg: MOMessage = self.request

        hdr = msg.header
        if hdr:
            _log.info(
                "hdr: \n"
                f"\t mtmsn: {hdr.mtmsn}\n"
                f"\t momsn: {hdr.momsn}\n"
                f"\t session status: {hdr.session_status}\n"
                f"\t imei: {hdr.imei}\n"
                f"\t cdr: {hdr.cdr}\n"
                f"\t time of session: {hdr.time_of_session}\n"
            )
        else:
            _log.warning("no header present")

        loc = msg.loc_info
        if loc:
            _log.info(
                "loc info:\n"
                f"\t lon: {loc.lon}\n"
                f"\t lat: {loc.lat}\n"
                f"\t CEP r: {loc.CEP_radius}\n"
            )
        else:
            _log.warning("no location info present")

        pay = msg.payload
        if pay:
            _log.info(f"payload: {pay.raw_payload}")
        else:
            _log.warning("no payload present")


# noinspection PyBroadException
def main(iface: str, port: int, blog_stream: typing.BinaryIO = None):
    server = MOServiceServer(
        server_address=(iface, port,),
        request_handler_cls=ReqHandler,
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
    logging.basicConfig(level=logging.DEBUG, stream=sys.stdout)

    parser = argparse.ArgumentParser("devutil SBD receiver", add_help=True)
    parser.add_argument("--iface", action="store", dest="iface", nargs="?", type=str, default="0.0.0.0")
    parser.add_argument("--port", action="store", dest="port", nargs="?", type=int, required=True)
    parser.add_argument("--blog-file", action="store", dest="blogfile", nargs="?", type=argparse.FileType('wb'),
                        default=None)

    args = parser.parse_args(sys.argv[1:])

    # Если нам предлагают писать данные в stdout, то оно не бинарное а текстовое
    # добудем из него бинарный поток (аттрибут buffer)
    stream = None
    if args.blogfile is not None:
        _log.info("using blog stream as %s", args.blogfile)
        stream = getattr(args.blogfile, "buffer", args.blogfile)

    arg_iface = args.iface
    arg_port = args.port

    return main(arg_iface, arg_port, stream)


if __name__ == "__main__":
    exit(main_exec())
