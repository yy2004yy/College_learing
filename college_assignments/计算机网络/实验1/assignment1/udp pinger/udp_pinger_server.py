
import random
import socket


serverSocket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

serverSocket.bind(('', 12350))

while True:
    rand = random.randint(0, 100)

    message, address = serverSocket.recvfrom(1024)

    print(address)

    message = message.upper()
    if rand>20:
        serverSocket.sendto(message, address)
