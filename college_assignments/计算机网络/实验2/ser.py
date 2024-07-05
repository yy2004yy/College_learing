import socket
import random
import time

# 定义服务器的IP地址和端口号
HOST = 'localhost'
PORT = 8080

# 创建套接字对象
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# 绑定地址和端口
server_socket.bind((HOST, PORT))

print("服务器正在监听端口", PORT)

# 接收数据并返回ACK
def receive_data(packet_loss_rate):
    packets_received = 0
    packets_lost = 0

    while True:
        data, client_address = server_socket.recvfrom(1024)

        if random.random() >= packet_loss_rate:  # 模拟丢包机制
            print("接收到的数据:", data.decode('utf-8'))
            ack = "ACK"
            server_socket.sendto(ack.encode('utf-8'), client_address)
            packets_received += 1
        else:
            print("丢失的数据:", data.decode('utf-8'))
            packets_lost += 1

# 开始接收数据
receive_data(0.5)  # 丢包率为0.5