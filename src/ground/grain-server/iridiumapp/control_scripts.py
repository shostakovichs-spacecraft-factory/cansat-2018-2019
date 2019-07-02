import logging
import sys

_log = logging.getLogger(__name__)

logging.basicConfig(level=logging.DEBUG, stream=sys.stdout)


from pymavlink.dialects.v10.zikush import MAVLink
from .network.mt_client import MTClient, MTMessage
from .messages.enum import MTDispositionFlags

mav = MAVLink(None, srcSystem=1, srcComponent=0)

mt_client = client = MTClient("localhost", 10800)

IMEI = "300234069205090"


def power_bus_control(busid, state):
    mav_msg = mav.zikush_cmd_powerbus_encode(busid, state)
    mav_msg_buf = mav_msg.pack(mav)
    mt_msg = MTMessage(
        uid=None,
        imei=IMEI,
        flags=MTDispositionFlags.FLUSH_MT_QUEUE,
        payload=mav_msg_buf,
        # priority=MTMessagePriority.PRIO_1
    )

    _log.info("message prepared")
    conf_msg = mt_client.send_message(mt_msg)

    _log.info("got confirmation message")
    _log.info("message sent as 0x%s" % ''.join('{:02x}'.format(x) for x in mav_msg_buf))

    cie = conf_msg.confirmation_ie
    _log.info(
        "conf:\n"
        f"\t uid: {cie.uid}\n"
        f"\t imei: {cie.imei}\n"
        f"\t status or queue number: {cie.status_or_queue_number}\n"
        f"\t ref-id: {cie.ref_id}\n"
    )


power_bus_control(3, 0)