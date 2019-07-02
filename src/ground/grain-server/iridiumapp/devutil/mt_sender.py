import sys
import argparse
import logging

from ..messages.mobile_terminated import MTMessage
from ..messages.enum import MTMessagePriority, MTDispositionFlags
from ..network.mt_client import MTClient

_log = logging.getLogger(__name__)


# noinspection PyBroadException
def main(host: str, port: int, imei: str, data: bytes):
    rc = 0

    try:
        msg = MTMessage(
            uid=None,
            imei=imei,
            flags=0, # MTDispositionFlags.FLUSH_MT_QUEUE,
            payload=data,
            # priority=MTMessagePriority.PRIO_1
        )

        _log.info("message prepared")
        hdr = msg.header_ie
        if not hdr:
            _log.warning("header ie is not present???")
        else:
            _log.info(
                "message header:\n"
                "\t uid: %s\n" % hdr.uid
                "\t imei: %s\n" % hdr.imei
                "\t flags: %s\n" % hdr.flags
            )

        prio = msg.prio_ie
        if not prio:
            _log.info("priority ie is not present")
        else:
            _log.info("prio: %s" % prio.priority_level)

        pload = msg.payload_ie
        if not pload:
            _log.info("payload ie is not present")
        else:
            _log.info("payload: %s" % pload.payload_data)

        _log.info("prepearing client")
        client = MTClient(host, port)

        _log.debug("sending message")
        conf_msg = client.send_message(msg)

        _log.info("got confirmation message")
        cie = conf_msg.confirmation_ie
        _log.info(
            "conf:\n"
            "\t uid: %s\n" % cie.uid
            "\t imei: %s\n" % cie.imei
            "\t status or queue number: %s\n" % cie.status_or_queue_number
            "\t ref-id: %s\n" % cie.ref_id
        )

    except Exception:
        rc = 1
        _log.exception("An error occurred")

    return rc


def main_exec():
    logging.basicConfig(level=logging.DEBUG, stream=sys.stdout)

    parser = argparse.ArgumentParser("devutil MT mesage sender")
    parser.add_argument("--host", action="store", dest="host", nargs="?", type=str, default="localhost")
    parser.add_argument("--port", action="store", dest="port", nargs="?", type=int, required=True)
    parser.add_argument("--imei", action="store", dest="imei", nargs="?", type=str, required=True)
    parser.add_argument("infile", action="store", nargs="?", type=argparse.FileType('rb'), default="-")

    args = parser.parse_args(sys.argv[1:])

    # Если нам дают данные из stdin-а, то оно не бинарное а текстовое
    # добудем из него бинарный поток (аттрибут buffer)
    stream = getattr(args.infile, "buffer", args.infile)
    data = stream.read()
    host = args.host
    port = args.port
    imei = args.imei

    return main(host, port, imei, data)


if __name__ == "__main__":
    exit(main_exec())
