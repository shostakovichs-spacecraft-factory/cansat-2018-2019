from socketserver import BaseRequestHandler
from iridium.network.sbd_server import SBDServiceServer

import logging
logging.basicConfig(level=logging.DEBUG)


class ReqHandler(BaseRequestHandler):
    def handle(self):
        pass


server = SBDServiceServer(
    server_address=("0.0.0.0", 1221),
    request_handler_cls=ReqHandler,
    send_ack=True,
)

server.serve_forever()