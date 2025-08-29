import socket
import time

HOST = "localhost"
PORT = 8081  # Change to your server's port

with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as s:
    s.connect((HOST, PORT))

    print("testing chuncked requests")
    request_parts = [
        b"POST /upload HTTP/1.1\r\n",
        b"Host: localhost:8081\r\n",
        b"Transfer-Encoding: chunked\r\n",
        b"\r\n",
        b"5\r\nHello\r\n",
        b"6\r\n World\r\n",
        b"1\r\n!\r\n",
        b"0\r\n\r\n",
    ]
    for part in request_parts:
        s.sendall(part)
        print(f"Sent: {part.decode().strip()}")
        time.sleep(0.5)  # Wait half a second between sends
    data = s.recv(1024)
    print("\n--- Server Response ---")
    print(data.decode())

    print("--- Sending Pipelined Requests ---")
    # Create two complete, separate GET requests
    request1 = (
        b"GET / HTTP/1.1\r\n"
        b"Host: localhost:8081\r\n"
        b"Connection: keep-alive\r\n"
        b"\r\n"
    )

    request2 = (
        b"GET /nonexistent.html HTTP/1.1\r\n"
        b"Host: localhost:8081\r\n"
        b"Connection: close\r\n"
        b"\r\n"
    )

    # Concatenate them into a single payload to simulate pipelining
    pipelined_request = request1 + request2
    s.sendall(pipelined_request)
    print("Payload sent.")

    # Set a timeout so we don't wait forever
    s.settimeout(2)

    full_response = b""
    try:
        while True:
            # Keep receiving data until the server closes the connection or times out
            data = s.recv(4096)
            if not data:
                break
            full_response += data
    except socket.timeout:
        print("\nSocket timed out. Received all available data.")

    print("\n--- Full Server Response ---")
    print(full_response.decode(errors="ignore"))
