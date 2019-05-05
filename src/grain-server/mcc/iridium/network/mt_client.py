import socket

from ..messages.mobile_terminated import MTMessage, MTMessageConfirmation
from ..messages.serialization import MessageSerializer, MessageParser
from ..messages.enum import MTMessagePriority

from .requisites import DIRECTIP_GATEWAY_ADDRESS


class MTClient:
    """ Клиент для оптравки MT сообщений шлюзу иридиума """

    TIMEOUT = 10
    """ Таймаут для оперцаий на сокете в секундах """

    RCV_BUFFER_SIZE = 4096
    """ размер буфера для приёма информации от шлюза """

    def __init__(self, host: str = DIRECTIP_GATEWAY_ADDRESS[0], port: int = DIRECTIP_GATEWAY_ADDRESS[1]):
        self.host = host
        self.port = port

        self.serializer = MessageSerializer()
        self.parser = MessageParser(MTMessageConfirmation)

    def send_simple_message(
            self,
            imei: str,  # IMEI модема, на который отправляется сообщение
            payload: bytes,
            priority: MTMessagePriority = None,  # Пририрет сообщения
    ):
        msg = MTMessage(
            imei=imei,
            priority=priority,
            payload=payload,
        )

    def send_message(self, message: MTMessage):
        """ Самый "низкий" уровень. Отправка сообщения, подготовленного где-то во вне
            и получение в ответ сырого сообщения-подтверждения
        """

        msg_bytes = self.serializer.serialize(message)

        sock = self._get_socket()
        try:
            sock.connect((self.host, self.port,))
            sock.sendall(msg_bytes)
            # так, все отправили - шлем EOF
            sock.shutdown(socket.SHUT_WR)

            conf_msg = self._read_confirmation(sock)
        finally:
            sock.close()

        return conf_msg

    def _get_socket(self):
        """ Получение объекта сокета как он есть """
        rv = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        rv.settimeout(self.TIMEOUT)
        return rv

    def _read_confirmation(self, sock: socket.socket)->MTMessageConfirmation:
        """ Вычитывание из сокета ответного сообщения и его парсинг """
        accum = bytes()
        while True:
            data = sock.recv(self.RCV_BUFFER_SIZE)
            if not data:  # получение EOF
                break

            accum += data

        conf_msg = self.parser.parse(data)  # type: MTMessageConfirmation
        return conf_msg
