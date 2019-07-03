import typing
from enum import IntEnum


class SessionStatus(IntEnum):
    """ Статусы SBD сессий """

    SUCESS = 0
    """ The SBD session completed successfully. """

    MO_OK_MT_TOO_LARGE = 1
    """ The MO message transfer, if any, was successful. The MT
        message queued at the Iridium Gateway is too large to be
        transferred within a single SBD session """

    MO_OK_BAD_LOC = 2
    """ The MO message transfer, if any, was successful. The reported
        location was determined to be of unacceptable quality. This
        value is only applicable to IMEIs using SBD protocol revision 1. """

    TIMEOUT = 10
    """ The SBD session timed out before session completion. """

    MO_TOO_LARGE = 12
    """ The MO message being transferred by the IMEI is too large to
        be transferred within a single SBD session. """

    RF_LINK_LOSS = 13
    """ An RF link loss occurred during the SBD session """

    IMEI_ANOMALY = 14
    """ An IMEI protocol anomaly occurred during SBD session """

    IMEI_PROHIBITED = 15
    """ The IMEI is prohibited from accessing the Iridium Gateway """


class IEI(IntEnum):
    """ Идентификаторы Information Element-ов """
    MO_HEADER = 0x01
    MO_PAYLOAD = 0x02
    MO_LOCATION_INFORMATION = 0x03
    M0_CONFIRMATION = 0x05

    MT_HEADER = 0x41
    MT_PAYLOAD = 0x42
    MT_CONFIRMATION = 0x44
    MT_MESSAGE_PRIORITY = 0x46


class ConfirmationStatus(IntEnum):
    """ Очевидно... """
    SUCCESS = 1
    FAILURE = 0

    def __bool__(self):
        return self == ConfirmationStatus.SUCCESS


class MTDispositionFlags(IntEnum):
    """ дополнительные флаги для mobile terminated сообщений """

    FLUSH_MT_QUEUE = 1
    """ Delete all MT payloads in the SSD’s MT queue """

    SEND_RING_ALERT = 2
    """ Send ring alert with no associated MT payload (normal ring alert rules apply) """

    UPDATE_SSD_LOC = 8
    """ Update SSD location with given lat/lon values """

    HIGH_PRIO = 16
    """ Place the associated MT payload in queue based on priority level """

    ASSIGN_MTMSN = 32
    """ Use the value in the Unique ID field as the MTMSN """


class MTMessageStatus(IntEnum):
    """ Статус обработки MT сообщения терминалом
        Значения от 1 до 50 обозначают успешное постановление сообщения в очередь
        и означают номер сообщения в MT очереди, поэтому этот енум их не покрывает
    """

    @classmethod
    def parse(cls, value: int):
        """ Специальный метод для парсинга значений с учетом валидных значений от 1 до 50 """
        if 0 <= value <= 50:
            return value
        else:
            return cls(value)

    SUCCESS_NO_PAYLOAD = 0
    """ Successful, no payload in message """

    IMEI_INVALID = -1
    """ Invalid IMEI – too few characters, non-numeric characters """

    IMEI_UNKNOWN = -2
    """ Unknown IMEI – not provisioned on the Iridium Gateway """

    PAYLOAD_SIZE_EXCEEDED = -3
    """ Payload size exceeded maximum allowed """

    PAYLOAD_EXPECTED = -4
    """ Payload expected, but none received """

    QUEUE_IS_FULL = -5
    """ MT message queue full (max of 50) """

    MT_UNAVAILABLE = -6
    """ MT resources unavailable """

    PROTOCOL_ERROR = -7
    """ Violation of MT DirectIP protocol error """

    RING_ALERTS_DISABLED = -8
    """ Ring alerts to the given IMEI are disabled """

    IMEI_NOT_ATTACHED = -9
    """ The given IMEI is not attached (not set to receive ring alerts) """

    IP_REJECTED = -10
    """ Source IP address rejected by MT filter """

    MTMSN_OUT_OF_RANGE = -11
    """ MTMSN value is out of range (valid range is 1 – 65,535)s """


class MTMessagePriority:
    """ Приоритет отправляемого сообщения
        1 - наивысший приоритет. 5 - низший
        Любое значение не из диапазона 1-5 считается как 5
    """

    PRIO_1 = 1
    PRIO_2 = 2
    PRIO_3 = 3
    PRIO_4 = 4
    PRIO_5 = 5
