import typing
from .enum import IEI as IEIEnum


class InformationElement:
    """ Информационный элемент. Сообщения состоят из информационных элементов.
        Этот класс олицетворяет такие элементы
    """

    IEI: IEIEnum = None
    """ Идентификатор информационного элемента. Реализуется в сабклассе """

    def unpack(self, ie_payload):
        """ Парсинг тела элемента """
        self._unpack_body(ie_payload)

    def pack(self)->bytes:
        """ Запаковка тела сообщения """
        return self._pack_body()

    def _unpack_body(self, body_data: bytes):
        """ Парсинг тела элемента. Реализуется в сабклассе """
        raise NotImplementedError()

    def _pack_body(self)->bytes:
        """ Запаковка тела элемента. Реализуется в сабклассе """
        raise NotImplementedError()


class Message:
    """ SBD сообщение. Отправляется либо от нас, либо от иридиумовского шлюза """

    IE_CLASSES: typing.List[typing.Type[InformationElement]] = []
    """ Список Information Element классов, которые могут попадаться в этом сообщении """

    def __init__(self):
        # Ключ словарика - идентификатор IE. Значение - само IE
        self.ies: typing.Dict[int, InformationElement] = {}

    def add_ie(self, ie: InformationElement):
        """ Добавиления IE к этому сообщению """
        if ie.__class__ not in self.IE_CLASSES:
            raise ValueError(f"Invalid IE class {ie.__class__} added to message")

        self.ies[ie.IEI] = ie
