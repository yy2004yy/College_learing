import socket
import sys


HOST, PORT = 'localhost', 12350
serverSocket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
serverSocket.bind((HOST, PORT))
serverSocket.listen(1)

while True:
    # Establish the connection
    print("Ready to serve...")
    connectionSocket, addr = serverSocket.accept()

    message = connectionSocket.recv(2048)
    print(type(message))
    print(message)
    if message == b'':
        continue

    # filename = message.split()[1].decode()
    filename = message.split()[1].decode('utf-8', 'replace')

    filename = "index.html" if filename == "/" else filename[1:]
    print("filename: {}".format(filename))

    try:
        with open(filename, "r") as f:
            outputdata = f.read()
        response = ("HTTP/1.1 200 OK\n"
                    "Server: Python 3.7.2\n"
                    "Content-Type: text/html; charset=utf-8\r\n\n")
        connectionSocket.send(response.encode())

        for i in range(0, len(outputdata)):
            connectionSocket.send(outputdata[i].encode())

        connectionSocket.send("\r\n".encode())
        connectionSocket.close()
    except FileNotFoundError:
        response = ("HTTP/1.1 404 Not Found\n"
                    "Server: Python 3.7.2\n"
                    "Content-Type: text/html; charset=utf-8\r\n\n")
        connectionSocket.sendall(response.encode())
        connectionSocket.close()



