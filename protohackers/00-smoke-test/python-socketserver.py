"""
Solution for protohackers smoke test problem using Python's socketserver module.

References used:
* https://docs.python.org/3/library/socketserver.html#socketserver-tcpserver-example
* https://docs.python.org/3/library/socketserver.html#socketserver.StreamRequestHandler
"""

from socketserver import ForkingTCPServer, StreamRequestHandler
import socket

class EchoHandler(StreamRequestHandler):
    def handle(self):
        print(f"Connection from {self.client_address}")
        self.data = self.rfile.read()
        #print(f"Received: {self.data}")
        self.wfile.write(self.data)

class ForkingTCPServerV6(ForkingTCPServer):
    address_family = socket.AF_INET6

if __name__ == "__main__":
    HOST, PORT = "::", 9999
    with ForkingTCPServerV6((HOST, PORT), EchoHandler) as server:
        print(f"Serving on {HOST}:{PORT}")
        server.serve_forever()
