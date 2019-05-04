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


class ConfirmationStatus(IntEnum):
    """ Очевидно... """
    SUCCESS = 1
    FAILURE = 0
