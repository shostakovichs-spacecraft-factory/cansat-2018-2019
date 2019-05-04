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

    def insert_ie(self, ie: InformationElement):
        """ Добавиления IE к этому сообщению
            Если такой IE уже есть в сообщении - перезаписывает его """
        if ie.__class__ not in self.IE_CLASSES:
            raise ValueError(f"Invalid IE class {ie.__class__} added to message")

        self.ies[ie.IEI] = ie

    def get_ie(self, iei: IEIEnum, default=None):
        """ Получение IE из сообщения по его идентификатору"""
        return self.ies.get(iei, default)
