import argparse
import socket
import sys

from ..sbd.serialization import MessageParser
from ..sbd.mobile_originated import MOMessageConfirmation


def main(host, port, stream):
    conf_parser = MessageParser(MOMessageConfirmation)

    sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    sock.connect((host, port,))
    sock.sendall(stream.read())
    sock.shutdown(socket.SHUT_WR)

    rc = 0
    try:
        accum = bytes()
        while True:
            data = sock.recv(4096)
            if not data:  # получили EOF
                break
            accum += data
        if not accum:
            print("got no data in response")

        msg = conf_parser.parse(accum)
        print("got some message in response: %s" % msg)
    except Exception:
        rc = 1
        raise

    finally:
        print("WHAT")
        sock.close()

    return rc


if __name__ == "__main__":
    parser = argparse.ArgumentParser("fake SBD sender", add_help=True)
    parser.add_argument("--host", action="store", dest="host", nargs="?", type=str, default="localhost")
    parser.add_argument("--port", action="store", dest="port", nargs="?", type=int, required=True)
    parser.add_argument("infile", action="store", nargs="?", type=argparse.FileType('rb'), default="-")

    import sys
    args = parser.parse_args(sys.argv[1:])

    # Если нам дают данные из stdin-а, то оно не бинарное а текстовое
    # добудем из него бинарный поток (аттрибут buffer)
    stream = getattr(args.infile, "buffer", args.infile)
    rc = main(args.host, args.port, stream)
    exit(rc)

