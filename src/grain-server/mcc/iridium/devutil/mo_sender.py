import argparse
import socket
import sys
import logging

from ..messages.serialization import MessageParser
from ..messages.mobile_originated import MOMessageConfirmation


_log = logging.getLogger(__name__)


def main(host, port, stream):
    conf_parser = MessageParser(MOMessageConfirmation)

    rc = 0
    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    try:
        _log.info(f"connecting to {host}:{port}")
        sock.connect((host, port,))
        _log.info("sending data")
        sock.sendall(stream.read())
        _log.debug("data sent, sending EOF")
        sock.shutdown(socket.SHUT_WR)
        _log.debug("eof sent")

        accum = bytes()
        while True:
            data = sock.recv(4096)
            if not data:  # получили EOF
                break
            accum += data
        if not accum:
            _log.info("got no data in response")
        else:
            msg = conf_parser.parse(accum)
            if isinstance(msg, MOMessageConfirmation):
                _log.info("got confirmation message with status: %s" % msg.conf_status)
            else:
                _log.info("got some message in response: %s" % msg)

    except Exception:
        _log.exception("An error occurred")
        rc = 1

    finally:
        sock.close()

    _log.info("end of it")
    return rc


if __name__ == "__main__":
    logging.basicConfig(level=logging.DEBUG, stream=sys.stdout)

    parser = argparse.ArgumentParser("devutil SBD sender", add_help=True)
    parser.add_argument("--host", action="store", dest="host", nargs="?", type=str, default="localhost")
    parser.add_argument("--port", action="store", dest="port", nargs="?", type=int, required=True)
    parser.add_argument("infile", action="store", nargs="?", type=argparse.FileType('rb'), default="-")

    args = parser.parse_args(sys.argv[1:])

    # Если нам дают данные из stdin-а, то оно не бинарное а текстовое
    # добудем из него бинарный поток (аттрибут buffer)
    stream = getattr(args.infile, "buffer", args.infile)
    rc = main(args.host, args.port, stream)
    exit(rc)

