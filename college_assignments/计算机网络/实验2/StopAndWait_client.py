import socket
import random
import time
from datetime import datetime
import statistics

# 定义服务器的IP地址和端口号
HOST = '127.0.0.1'
PORT = 8080

# 创建套接字
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# 设置超时时间：如果套接字操作耗时超过1秒，将引发套接字超时异常
client_socket.settimeout(1)


# 定义函数send_data(packet_loss_rate1, num_packets)，发送数据并接收ACK
def send_data(packet_loss_rate1, num_packets):
    packets_sent = 0
    packets_lost = 0
    rtt_times = []

    for i in range(num_packets):
        message = "Packet" + str(i + 1)
        data = str(packet_loss_rate1) + ',' + message  # 先把数字变量转化为字符串再传输
        client_socket.sendto(data.encode('utf-8'), (HOST, PORT))
        packets_sent += 1  # 将packets_sent变量加1，以记录发送的数据包数量

        try:
            start_time = datetime.now()
            data, server_address = client_socket.recvfrom(1024)
            end_time = datetime.now()
            rtt = (end_time - start_time).total_seconds() * 1000
            rtt_times.append(rtt)
            print("接收到服务器的ACK:", data.decode('utf-8'))
        except socket.timeout:
            print("超时，重新发送数据:", message)
            packets_lost += 1
            continue

        # time.sleep(0.1)  # 延迟0.1秒

    packet_loss_rate = packets_lost / packets_sent * 100
    average_rtt = statistics.mean(rtt_times)
    total_time = sum(rtt_times)

    print("发送的数据包数量:", packets_sent)
    print("丢包率:", packet_loss_rate, "%")
    print("平均往返时间（RTT）:", average_rtt, "ms")
    print("总时间:", total_time, "ms")


# 发送数据
send_data(0.5, 10)  # 发送10个数据包，丢包率为0.5
print("--------------------")
send_data(0.2, 100)  # 发送100个数据包，丢包率为0.2
print("--------------------")
send_data(0.5, 100)  # 发送100个数据包，丢包率为0.5
print("--------------------")
