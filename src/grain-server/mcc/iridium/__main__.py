from socketserver import BaseRequestHandler
from iridium.network.sbd_server import SBDServiceServer


class ReqHandler(BaseRequestHandler):
    def handle(self):
        print(self.request)


server = SBDServiceServer(
    server_address=("0.0.0.0", 1221),
    request_handler_cls=ReqHandler
)

server.serve_forever()