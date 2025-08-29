"""
Solution for protohackers prime time problem using Python's socketserver module.
"""

from socketserver import ForkingTCPServer, StreamRequestHandler
import socket
import json
import math


def is_prime(num):
    if not isinstance(num, int):
        return False
    if num <= 1:
        return False
    for i in range(2, int(math.sqrt(num)) + 1):
        if num % i == 0:
            return False
    return True


class EchoHandler(StreamRequestHandler):
    def handle(self):
        print(f"Connection from {self.client_address}")
        while line := self.rfile.readline():
            print(f"Received: {line}")
            is_malformed = False
            try:
                request: dict = json.loads(line)
                if (
                    request.get("method") == "isPrime"
                    and isinstance(request.get("number"), (int, float))
                    and not isinstance(request.get("number"), bool)
                ):
                    self.wfile.write(
                        json.dumps(
                            {
                                "method": "isPrime",
                                "prime": is_prime(request.get("number")),
                            }
                        ).encode()
                        + b"\n"
                    )
                else:
                    is_malformed = True
            except json.JSONDecodeError:
                is_malformed = True
            if is_malformed:
                self.wfile.write(b"{}\n")
                break


class ForkingTCPServerV6(ForkingTCPServer):
    address_family = socket.AF_INET6
    allow_reuse_address = True


if __name__ == "__main__":
    HOST, PORT = "::", 9999
    with ForkingTCPServerV6((HOST, PORT), EchoHandler) as server:
        print(f"Serving on {HOST}:{PORT}")
        server.serve_forever()
