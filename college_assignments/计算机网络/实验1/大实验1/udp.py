import datetime
import statistics
import random
import socket


# 创建UDP套接字
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# 设置服务器地址和端口号
server_address = ('localhost', 12345)

rtt_list = []  # 存储RTT的列表

for i in range(10):
    # 生成随机数，模拟数据包丢失
    if random.randint(1, 100) > 10:
        # 发送ping消息
        send_time = datetime.datetime.now()
        client_socket.sendto(b'ping', server_address)

        try:
            # 等待服务器的响应
            client_socket.settimeout(1)
            response, server_address = client_socket.recvfrom(1024)
            receive_time = datetime.datetime.now()

            # 计算RTT并添加到列表中
            rtt = (receive_time - send_time).total_seconds()
            rtt_list.append(rtt)

            # 打印服务器的响应消息和RTT
            print(f"Response: {response.decode()}")
            print(f"RTT: {rtt} seconds")
        except socket.timeout:
            # 数据包丢失，打印请求超时
            print("请求超时")

# 计算RTT的平均值
avg_rtt = statistics.mean(rtt_list)
print(f"Average RTT: {avg_rtt} seconds")

# 关闭套接字
client_socket.close()

