import socket
import random
import time

# 定义服务器的IP地址和端口号
HOST = '127.0.0.1'
PORT = 8080

# 创建套接字
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# 绑定地址和端口
server_socket.bind((HOST, PORT))

print("服务器正在监听端口", PORT)

# 定义函数receive_data()，接收数据并返回ACK
def receive_data():
    while True:
        data, client_address = server_socket.recvfrom(1024)
        packet_loss_rate1 = float(data.decode('utf-8').split(',')[0])
        message = data.decode('utf-8').split(',')[1]

        if random.random() >= packet_loss_rate1:  # 模拟不同丢包率的丢包机制
            print("接收到的重发数据:", message)
            ack = "ACK"
            server_socket.sendto(ack.encode('utf-8'), client_address)

# 开始接收数据
receive_data()