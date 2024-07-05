import socket
import random
import time

# 定义服务器的IP地址和端口号
HOST = '127.0.0.1'
PORT = 8080

# 创建套接字对象
server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# 绑定地址和端口
server_socket.bind((HOST, PORT))

# 开始监听连接
server_socket.listen()

print("服务器正在监听端口", PORT)

# 接收数据并返回ACK
def receive_data():
    client_socket, client_address = server_socket.accept()
    print("客户端", client_address, "已连接")

    while True:
        data = client_socket.recv(1024)
        if random.random() >= 0.5:  # 模拟丢包机制
            print("接收到的数据:", data.decode('utf-8'))
            ack = "ACK"
            client_socket.send(ack.encode('utf-8'))

# 开始接收数据
receive_data()