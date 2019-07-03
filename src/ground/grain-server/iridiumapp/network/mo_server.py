import typing
import socket
import logging
from socketserver import BaseRequestHandler, TCPServer

from ..messages.serialization import MessageParser as SBDMessageParser, MessageSerializer as SBDMessageSerializer
from ..messages.mobile_originated import Message, MOMessage, MOMessageConfirmation
from ..messages.enum import ConfirmationStatus

_log = logging.getLogger(__name__)


class _MOTcpRequestHandler(BaseRequestHandler):
    """ Хендлер TCP сообщений от иридиумного гейтевея """
    serializer = None

    def __init__(self, request, client_address, server):
        srv = server
        self.parser = srv.parser
        self.serializer = srv.serializer
        self.send_ack = srv.send_ack
        self.sbd_handler_cls = srv.sbd_handler_cls
        self.blog_stream = srv.blog_stream

        # Поскольку вся обработка проходит в конструкторе базы - вызываем его последним
        super().__init__(request, client_address, server)

    # noinspection PyBroadException
    def handle(self):
        _log.debug("got a request from %s", self.client_address)

        try:
            raw_data = self.read_all()
            if self.blog_stream:
                _log.debug("logging raw data to blog stream")
                self.blog_stream.write(raw_data)
                self.blog_stream.flush()

            msg = self.parser.parse(raw_data)
            _log.info("got SBD message: %s", msg)

            self.handle_sbd_message(msg)
            # Хендлер делает все свои дела в конструкторе (почему блин?)
            # поэтому если консторуктор отработал, то все ок

            if self.send_ack:
                self.send_ack_message(ConfirmationStatus.SUCCESS)
        except Exception:
            _log.exception("error on SBD message processing")
            if self.send_ack:
                self.send_ack_message(ConfirmationStatus.FAILURE)
                raise  # пихаем дальше

    def read_all(self):
        """ Парсинг SBD сообщения из всех байт полученных в сокет """
        sock = self.request # type: socket.socket

        # Читаем все что передал нам гейтвей иридиума
        accum = bytes()
        while True:
            data = sock.recv(4096)
            if not data:  # Значит получили EOF
                break
            accum += data

        return accum

    def handle_sbd_message(self, msg: Message):
        _log.debug("Handling messages message")

        self.sbd_handler_cls(
            request=msg,
            client_address=self.client_address,
            server=self.server,
        )

        _log.debug("messages message handled sucessfully")

    def send_ack_message(self, conf_status: ConfirmationStatus):
        _log.info("sending back ack message with conf status %s", conf_status)
        try:
            msg = MOMessageConfirmation(conf_status)
            msg_data = self.serializer.serialize(msg)
            sock = self.request  # type: socket.socket
            sock.send(msg_data)
        except OSError:
            _log.warning("Unable to send ACK message", exc_info=True)


class MOServiceServer(TCPServer):
    """ Сервер для приёма входящих SBD сообщений от иридиумового гетевея
        Работает как классичеческий socketserver. Для обработки запросов создает
        объект пользовательского класса, унаследованного от socketserver.BaseRequestHandler.
        В хендлере в качестве поля request используется SBD сообщение.
    """

    def __init__(
            self,
            server_address,
            request_handler_cls: typing.Type[BaseRequestHandler],
            bind_and_activate=True,
            send_ack=False,
            blog_stream: typing.BinaryIO = None
    ):
        """
        :param server_address:      Адрес сервера - кортеж с адресом интерфейса на котором слушаем
                                    и с TCP портом на котором слушаем
        :param request_handler_cls: Класс обрабатывающий поступающие сообщения
        :param bind_and_activate:   Параметр для конструктора TCPServer
        :param send_ack:            Нужно ли отправть MOMessageConfirmation сообщение шлюзу иридиума?
        :param blog_stream:         Стрим для логгирования сырых сообщений еще до их разбора
        """
        # А клиентский хендлер запоминаем для себя
        self.sbd_handler_cls = request_handler_cls

        self.send_ack = send_ack
        self.blog_stream = blog_stream

        # Создаем парсер для входящих MO сообщений
        self.parser = self._build_parser()
        # И сериализатор для MOConfirmation сообщений
        self.serializer = self._build_serializer()

        # Базовому классу дает свой собственный хендлер
        super().__init__(server_address, _MOTcpRequestHandler, bind_and_activate)

    # noinspection PyMethodMayBeStatic
    def _build_parser(self):
        return SBDMessageParser(MOMessage)

    # noinspection PyMethodMayBeStatic
    def _build_serializer(self):
        return SBDMessageSerializer()

    def server_close(self):
        if self.blog_stream:
            self.blog_stream.close()

        super().server_close()
