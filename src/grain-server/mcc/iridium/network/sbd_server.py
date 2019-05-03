import typing
import socket
import logging
from socketserver import BaseRequestHandler, TCPServer

from iridium.sbd.serialization import MessageParser as SBDMessageParser, MessageSerializer as SBDMessageSerializer
from iridium.sbd.mobile_originated import Message, MOMessage, MOMessageConfirmation
from iridium.sbd.enum import ConfirmationStatus

_log = logging.getLogger(__name__)


class _SBDTcpRequestHandler(BaseRequestHandler):
    """ Хендлер TCP сообщений от иридиумного гейтевея """

    def __init__(self, request, client_address, server):
        srv: SBDServiceServer = server
        self.parser = srv.parser
        self.serializer = srv.serializer
        self.send_ack = srv.SEND_ACK
        self.sbd_handler_cls = srv.sbd_handler_cls

        # Поскольку вся обработка проходит в конструкторе базы - вызываем его последним
        super().__init__(request, client_address, server)

    def handle(self):
        msg = self.read_sbd_message()
        try:
            self.handle_sbd_message(msg)
            # Хендлер делает все свои дела в конструкторе (почему блин?)
            # поэтому если консторуктор отработал, то все ок
            if self.send_ack:
                self.send_ack_message(ConfirmationStatus.SUCCESS)

            _log.info("Got sbd message:", msg)
        except Exception:
            _log.exception("Error on SBD message processing")
            if self.send_ack:
                self.send_ack_message(ConfirmationStatus.FAILURE)
                raise  # пихаем дальше

    def read_sbd_message(self):
        """ Парсинг SBD сообщения из всех байт полученных в сокет """
        sock: socket.socket = self.request

        # Читаем все что передал нам гейтвей иридиума
        accum = bytes()
        while True:
            data = sock.recv(4096)
            if not data:  # Значит получили EOF
                break
            accum += data

        msg = self.parser.parse(accum)
        return msg

    def handle_sbd_message(self, msg: Message):
        self.sbd_handler_cls(
            request=msg,
            client_address=self.client_address,
            server=self.server,
        )

    def send_ack_message(self, conf_status: ConfirmationStatus):
        try:
            msg = MOMessageConfirmation(conf_status)
            msg_data = self.serializer.serialize(msg)
            sock: socket.socket = self.request
            sock.send(msg_data)
        except Exception:
            _log.warning("Unable to send ACK message", exc_info=True)


class SBDServiceServer(TCPServer):
    """ Сервер для приёма входящих SBD сообщений от иридиумового гетевея
    """

    SEND_ACK = True
    """ Управляет отправкой подтверждений MOConfirmation при успешной обработке сообщения """

    def __init__(self, server_address, request_handler_cls: typing.Type[BaseRequestHandler]):
        # Базовому классу дает свой собственный хендлер
        super().__init__(server_address, _SBDTcpRequestHandler)

        # А клиентский хендлер запоминаем для себя
        self.sbd_handler_cls = request_handler_cls

        # Создаем парсер для входящих MO сообщений
        self.parser = self._build_parser()
        # И сериализатор для MOConfirmation сообщений
        self.serializer = self._build_serializer()

    def _build_parser(self):
        return SBDMessageParser(MOMessage)

    def _build_serializer(self):
        return SBDMessageSerializer()


class BasicSBDMessageHandler(BaseRequestHandler):
    def __init__(self, request, client_address, server):
        super().__init__(request, client_address, server)

    def setup(self):
        pass

    def handle(self):
        pass

    def finish(self):
        pass
