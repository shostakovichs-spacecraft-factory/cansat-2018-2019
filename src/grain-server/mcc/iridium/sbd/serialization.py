import typing
import struct
from .basic import Message

_IE_HEADER_STRUCT = struct.Struct(">BH")
""" Структура заголовка IEI"""

_MESSAGE_HEADER_STRUCT = struct.Struct(">BH")
""" Структура заголовка сообщения """

_PROTOCOL_VERSION = 1
""" Идентификатор протокола иридиума """


class MessageParser:
    """ Парсилка сообщений от иридиума
        Довольно глупая и ожидает только один тип входящих сообщений
    """

    IE_HEADER_STRUCT = _IE_HEADER_STRUCT
    """ Структура заголовка IEI"""

    MESSAGE_HEADER_STRUCT = _MESSAGE_HEADER_STRUCT
    """ Структура заголовка сообщения """

    PROTOCOL_VERSION = _PROTOCOL_VERSION
    """ Идентификатор протокола иридиума """

    def __init__(self, expected_message_class: typing.Type[Message]):
        self.msg_class = expected_message_class

        # Соберем себе словарик ожидаемых элементов из сообщения
        self._allowed_elemenents = {}
        for elem_class in self.msg_class.IE_CLASSES:
            self._allowed_elemenents[elem_class.IEI] = elem_class

    def parse(self, raw_data: bytes)->Message:
        retval = self.msg_class()

        msg_payload = self._msg_slice(raw_data)
        for iei, ie_payload in self._ie_iter(msg_payload):
            ie_class = self._allowed_elemenents[iei]
            ie = ie_class()
            ie.unpack(ie_payload)

            retval.add_ie(ie)

        return retval

    # ==============================
    # Служебные методы для парсинга
    # ==============================

    def _ie_slice(self, data: bytes):
        """ Выпаршивает первый IE из массива байт """

        header_size = self.IE_HEADER_STRUCT.size
        header, headless = data[0:header_size], data[header_size:]

        iei, size = self.IE_HEADER_STRUCT.unpack(header)
        ie_payload, leftovers = headless[:size], headless[size:]

        if len(ie_payload) != size:
            raise ValueError(
                f"invalid size for iei {iei}: {len(ie_payload)} while {size} were expected"
            )

        return iei, ie_payload, leftovers

    def _ie_iter(self, data: bytes):
        """ Парсинг самого верхнего уровня для информационных элементов
            Функция разделяет поток байтов на информационные элементы
            Работает как генератор. йилдит кортежи ie-id, ie-payload
        """

        while len(data) != 0:
            iei, ie_payload, leftovers = self._ie_slice(data)
            yield iei, ie_payload
            data = leftovers

    def _msg_slice(self, data: bytes):
        """ Режет сообщение на заголовок и "нагрузку" """
        header_size = self.MESSAGE_HEADER_STRUCT.size
        header, msg_payload = data[0:header_size], data[header_size:]
        protocol_version, size = self.MESSAGE_HEADER_STRUCT.unpack(header)

        if protocol_version != self.PROTOCOL_VERSION:
            raise ValueError(
                f"Invalid protocol version: {protocol_version}. {self.PROTOCOL_VERSION} were expected"
            )

        if size != len(msg_payload):
            raise ValueError(
               f"Invalid message size {len(msg_payload)}. {size} were expected"
            )

        return msg_payload


class MessageSerializer:
    """ Сериализатор SBD сообщений с нашей стороны """

    IE_HEADER_STRUCT = _IE_HEADER_STRUCT
    """ Структура заголовка IEI"""

    MESSAGE_HEADER_STRUCT = _MESSAGE_HEADER_STRUCT
    """ Структура заголовка сообщения """

    PROTOCOL_VERSION = _PROTOCOL_VERSION
    """ Идентификатор протокола иридиума """

    def serialize(self, msg: Message)->bytes:
        msg_payload = bytes()

        for iei, ie in msg.ies.items():
            msg_payload += self._ie_join(iei, ie.pack())

        msg_data = self._msg_join(msg_payload)
        return msg_data

    def _ie_join(self, iei: int, ie_payload: bytes):
        """ Построение IE в бинарной форме из идентификатора и его тела """
        size = len(ie_payload)
        data = _IE_HEADER_STRUCT.pack(iei, size)
        data += ie_payload
        return data

    def _msg_join(self, msg_payload: bytes):
        """ Режет сообщение на заголовок и "нагрузку" """
        header = self.MESSAGE_HEADER_STRUCT.pack(self.PROTOCOL_VERSION, len(msg_payload))
        return header + msg_payload
