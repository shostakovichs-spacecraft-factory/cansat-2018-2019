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
                "\t mtmsn: %s\n" % hdr.mtmsn
                "\t momsn: %s\n" % hdr.momsn
                "\t session status: %s\n" % hdr.session_status
                "\t imei: %s\n" % hdr.imei
                "\t cdr: %s\n" % hdr.cdr
                "\t time of session: %s\n" % hdr.time_of_session
            )
        else:
            _log.warning("no header present")

        loc = msg.loc_info
        if loc:
            _log.info(
                "loc info:\n"
                "\t lon: %s\n" % loc.lon
                "\t lat: %s\n" % loc.lat
                "\t CEP r: %d\n" % loc.CEP_radius
            )
        else:
            _log.warning("no location info present")

        pay = msg.payload
        if pay:
            _log.info("payload: %s" % pay.raw_payload)
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
