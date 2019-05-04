import typing
import struct

from .enum import IEI, MTDispositionFlags, MTMessageStatus
from .basic import InformationElement, Message


class MOIECounterGenerator:
    """ __cинглтон__, генерирующий последовательные UID для MT сообщений """

    START_VALUE = 0
    NEXT_VALUE = None
    UID_MASK = 0xffffffff

    @classmethod
    def next_uid(cls):
        if cls.NEXT_VALUE is None:
            cls.NEXT_VALUE = cls.START_VALUE

        next = cls.NEXT_VALUE
        cls.NEXT_VALUE = (cls.NEXT_VALUE + 1) & cls.UID_MASK
        return next


class MTIEHeader(InformationElement):
    """ Заголовок Mobile Originated сообщения """

    IEI = IEI.MT_HEADER
    BODY_STRUCT = struct.Struct(">L15sH")

    def __init__(self, uid: int = None, imei: str = None, flags: MTDispositionFlags = None):
        if uid is None:
            self.uid = MOIECounterGenerator.next_uid()
        else:
            self.uid = uid

        self.imei = imei
        self.flags = flags

    def _pack_body(self) -> bytes:

        return self.BODY_STRUCT.pack(
            self.uid,
            self.imei.encode("ascii"),
            self.flags.value if self.flags else 0,
        )

    def _unpack_body(self, body_data: bytes):
        raise NotImplementedError()


class MTIEPayload(InformationElement):
    """ Полезная нагрузка для MT сообщения """

    IEI = IEI.MT_PAYLOAD

    def __init__(self, payload_data: bytes = None):
        self.payload_data = payload_data

    def _pack_body(self) -> bytes:
        return self.payload_data if self.payload_data else bytes()

    def _unpack_body(self, body_data: bytes):
        raise NotImplementedError()


class MTIEPriority(InformationElement):
    """ Приоритет MT сообщения """

    IEI = IEI.MT_MESSAGE_PRIORITY
    BODY_STRUCT = struct.Struct(">H")

    def __init__(self, priority_level: int = None):
        """ Допустимые значения от 1 до 5. Все остальное преобразуется в 5 """
        self.priority_level = priority_level

    def _pack_body(self) -> bytes:
        return self.BODY_STRUCT.pack(self.priority_level)

    def _unpack_body(self, body_data: bytes):
        raise NotImplementedError()


class MTIEConfirmation(InformationElement):
    """ Подтверждение от шлюза о получении нашего сообщения и постановке его в очередь """

    IEI = IEI.MT_CONFIRMATION
    BODY_STRUCT = struct.Struct(">L15sLH")

    def __init__(self):
        self.uid: int = None
        self.imei: str = None
        self.ref_id: int = None
        self.status: typing.Union[int, MTMessageStatus] = None

    def _pack_body(self) -> bytes:
        raise NotImplementedError()

    def _unpack_body(self, body_data: bytes):
        uid, imei, ref_id, status = self.BODY_STRUCT.unpack(body_data)

        self.uid = uid
        self.imei = imei
        self.ref_id = ref_id
        self.status = MTMessageStatus.parse(status)


class MTMessage(Message):
    """ Сообщение для шлюза иридиума с содержимым MT сообщением """

    IE_CLASSES = [MTIEHeader, MTIEPayload, MTIEPriority]

    def __init__(
            self,
            uid: int = None,
            imei: str = None,
            flags: str = None,
            priority: int = None,
            payload: bytes = None,
    ):
        super().__init__()
        if uid or imei or flags:
            self.insert_ie(MTIEHeader(uid=uid, imei=imei, flags=flags))

        if payload:
            self.insert_ie(MTIEPayload(payload_data=payload))

        if priority:
            self.insert_ie(MTIEPriority(priority_level=priority))


    @property
    def header_ie(self)->typing.Optional[MTIEHeader]:
        return self.get_ie(MTIEHeader.IEI)

    @header_ie.setter
    def header_ie(self, value: MTIEHeader):
        self.insert_ie(value)


    @property
    def payload_ie(self)->typing.Optional[MTIEPayload]:
        return self.get_ie(MTIEPayload.IEI)

    @payload_ie.setter
    def payload_ie(self, value: MTIEPayload):
        self.insert_ie(value)


    @property
    def payload(self)->typing.Optional[bytes]:
        ie: MTIEPayload = self.get_ie(MTIEPayload.IEI)
        return ie.payload_data if ie else None

    @payload.setter
    def payload(self, value: bytes):
        self.insert_ie(MTIEPayload(payload_data=value))


    @property
    def prio_ie(self)->typing.Optional[MTIEPriority]:
        return self.get_ie(MTIEPriority.IEI)

    @prio_ie.setter
    def prio_ie(self, value: MTIEPriority):
        self.insert_ie(value)


    @property
    def priority(self)->typing.Optional[int]:
        ie: MTIEPriority = self.get_ie(MTIEPriority.IEI)
        return ie.priority_level if ie else None

    @priority.setter
    def priority(self, value: int):
        self.insert_ie(MTIEPriority(priority_level=value))


class MTMessageConfirmation(Message):
    """ Сообщение от шлюза иридиума с подтверждением получения и обработки MT сообщения """

    IE_CLASSES = [MTIEConfirmation]

    @property
    def confirmation_ie(self)->typing.Optional[MTIEConfirmation]:
        return self.get_ie(MTIEConfirmation.IEI)

    @confirmation_ie.setter
    def confirmation_ie(self, value: MTIEConfirmation):
        self.insert_ie(value)
