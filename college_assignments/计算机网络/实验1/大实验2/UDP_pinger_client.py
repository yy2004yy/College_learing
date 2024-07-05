import socket
import datetime
import statistics
import random
import time

# 设置服务器地址和端口
server_address = ('localhost', 12345)

# 设置要发送的ping消息数量
num_messages = 10

# 创建一个UDP套接字
client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# 将超时设置为1秒
client_socket.settimeout(1)

# 列表用于存储往返时间（RTT）
rtt_list = []

for seq in range(1, num_messages+1):
    try:
        # 发送ping消息之前获取当前时间
        start_time = datetime.datetime.now()

        # 生成随机的丢包情况
        if random.randint(1, 10) > 3:
            # 向服务器发送ping消息
            message = f'Ping {seq}'
            client_socket.sendto(message.encode(), server_address)

            # 从服务器接收pong消息
            response, server = client_socket.recvfrom(1024)

            # 在接收到pong消息后获取当前时间
            end_time = datetime.datetime.now()

            # 计算往返时间（RTT）
            rtt = (end_time - start_time).total_seconds()
            rtt_list.append(rtt)

            # 延时1秒
            time.sleep(1)

            # 打印响应消息和RTT
            print(f'来自服务器的响应：{response.decode()}')
            print(f'RTT：{rtt} 秒')
        else:
            # 模拟丢包
            raise socket.timeout

    except socket.timeout:
        # 如果在1秒内没有收到响应，则假定丢包
        print(f'Ping {seq} 的请求超时')

# 延时1秒
time.sleep(1)

# 计算并打印平均RTT
if rtt_list:
    avg_rtt = statistics.mean(rtt_list)
    print(f'\n平均RTT：{avg_rtt} 秒')

# 关闭套接字
client_socket.close()
