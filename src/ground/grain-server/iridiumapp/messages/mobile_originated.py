import typing
import struct
import datetime as dt

from .enum import SessionStatus, IEI, ConfirmationStatus
from .basic import InformationElement, Message


class MOIEHeader(InformationElement):
    """ Заголовок Mobile Originated сообщения """

    IEI = IEI.MO_HEADER
    BODY_STRUCT = struct.Struct(">L15sBHHL")

    def __init__(self):
        self.cdr = None  # type: int
        self.imei = None  # type: str
        self.session_status = None  # type: ConfirmationStatus
        self.momsn = None  # type: int
        self.mtmsn = None  # type: int
        self.time_of_session = None  # type: dt.datetime

    def _pack_body(self) -> bytes:
        raise NotImplementedError()

    def _unpack_body(self, body_data: bytes):
        values = self.BODY_STRUCT.unpack(body_data)

        cdr = values[0]
        imei = values[1].decode("utf-8")
        session_status = SessionStatus(values[2])
        momsn = values[3]
        mtmsn = values[4]
        time_of_session = dt.datetime.fromtimestamp(values[5], tz=dt.timezone.utc)

        self.cdr = cdr
        self.imei = imei
        self.session_status = session_status
        self.momsn = momsn
        self.mtmsn = mtmsn
        self.time_of_session = time_of_session


class MOIEPayload(InformationElement):
    """ Полезная нагрузка от терминала в Mobile Originated сообщении """
    IEI = IEI.MO_PAYLOAD

    def __init__(self):
        self.raw_payload = None  # type: bytes

    def _pack_body(self) -> bytes:
        raise NotImplementedError()

    def _unpack_body(self, body_data: bytes):
        self.raw_payload = body_data


class MOIELocationInformation(InformationElement):
    """ Информация о положении терминала, которую вычисляет система иридиума """
    IEI = IEI.MO_LOCATION_INFORMATION
    BODY_STRUCT = struct.Struct(">BBHBHL")

    def __init__(self):
        self.lat = None  # type: float
        self.lon = None  # type: float
        self.CEP_radius = None  # type: int

    def _pack_body(self) -> bytes:
        raise NotImplementedError()

    def _unpack_body(self, body_data: bytes):
        codes, lat, latmins, lon, lonmins, cepr = self.BODY_STRUCT.unpack(body_data)

        # Проверяем коды на валидность
        if codes & 0xfc != 0:
            raise ValueError("Invalid Data in geoloc flags 0x%02X" % codes)

        # Пересчитываем долготу и широту в человеческие значения
        latmins, lonmins = latmins/1000, lonmins/1000
        lat = lat + latmins/60
        lon = lon + lonmins/60

        # Учитываем знаки
        if codes & 0x02 != 0:
            lat *= -1

        if codes & 0x01 != 0:
            lon *= -1

        self.lat = lat
        self.lon = lon
        self.CEP_radius = cepr


class MOIEConfirmation(InformationElement):
    """ Подтверждение о получении сообщения нашей службой. Отправляется в ответ шлюзу на MO сообщение """
    IEI = IEI.M0_CONFIRMATION

    def __init__(self, confirmation_status: ConfirmationStatus = ConfirmationStatus.SUCCESS):
        self.confirmation_status = confirmation_status

    def set_status(self, value: ConfirmationStatus):
        self.confirmation_status = value

    def _pack_body(self)->bytes:
        return bytes([self.confirmation_status])

    def _unpack_body(self, body_data: bytes):
        self.confirmation_status = ConfirmationStatus(body_data[0])


class MOMessage(Message):
    """ SBD сообщение с терминала, которое передает нам шлюз иридиума """
    IE_CLASSES = [MOIEHeader, MOIEPayload, MOIELocationInformation]

    @property
    def header(self) -> typing.Optional[MOIEHeader]:
        return self.get_ie(MOIEHeader.IEI)

    @header.setter
    def header(self, value: MOIEHeader):
        self.insert_ie(value)

    # ===
    @property
    def loc_info(self) -> typing.Optional[MOIELocationInformation]:
        return self.get_ie(MOIELocationInformation.IEI)

    @loc_info.setter
    def loc_info(self, value: MOIELocationInformation):
        self.insert_ie(value)

    # ===
    @property
    def payload(self) -> typing.Optional[MOIEPayload]:
        return self.get_ie(MOIEPayload.IEI)

    @payload.setter
    def payload(self, value: MOIEPayload):
        self.insert_ie(value)


class MOMessageConfirmation(Message):
    """ Сообщение о подтверждении получения сообщения.
        Если требуется иридиумом (настривается через диллера), должно быть отправлено в ответ
        на полученное MO сообщение в том же соединении """
    IE_CLASSES = [MOIEConfirmation]

    def __init__(self, confirmation_status: ConfirmationStatus = None):
        super().__init__()
        if confirmation_status is not None:
            self.insert_ie(MOIEConfirmation(confirmation_status))

    # ===
    @property
    def conf_ie(self) -> typing.Optional[MOIEConfirmation]:
        return self.get_ie(MOIEConfirmation.IEI)

    @conf_ie.setter
    def conf_ie(self, value: MOIEConfirmation):
        self.insert_ie(value)

    # ===
    @property
    def conf_status(self)->typing.Optional[ConfirmationStatus]:
        ie = self.conf_ie
        return ie.confirmation_status if ie else None

    @conf_status.setter
    def conf_status(self, value: ConfirmationStatus):
        ie = MOIEConfirmation(confirmation_status=value)
        self.insert_ie(ie)
