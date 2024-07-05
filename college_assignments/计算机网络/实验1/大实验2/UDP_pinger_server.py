import socket

# 设置服务器地址和端口
server_address = ('localhost', 12345)

# 创建一个UDP套接字
server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

# 将套接字绑定到服务器地址和端口
server_socket.bind(server_address)

while True:
    # 从客户端接收ping消息
    message, client_address = server_socket.recvfrom(1024)

    # 用pong消息进行回应
    response = f'Pong：{message.decode()}'
    server_socket.sendto(response.encode(), client_address)
