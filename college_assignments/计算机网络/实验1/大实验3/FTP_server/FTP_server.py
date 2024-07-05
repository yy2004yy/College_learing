import socket
import os

HOST = '127.0.0.1'  # 服务器 IP 地址
PORT = 9090  # 服务器端口号
BUFFER_SIZE = 1024  # 缓冲区大小

def handle_client(client_socket):
    # 接收客户端发送的文件名
    file_name = client_socket.recv(BUFFER_SIZE).decode()
    print(f"Received request for file: {file_name}")

    # 检查文件是否存在
    if not os.path.exists(file_name):
        error_msg = f"File '{file_name}' does not exist"
        print(error_msg)
        client_socket.send(error_msg.encode())
        return

    # 发送文件数据
    with open(file_name, 'rb') as file:
        while True:
            data = file.read(BUFFER_SIZE)
            if not data:
                break
            client_socket.send(data)

    print(f"File '{file_name}' sent successfully")
    client_socket.close()

def run_server():
    # 创建服务器套接字
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((HOST, PORT))
    server_socket.listen(1)
    print(f"Server listening on {HOST}:{PORT}")

    while True:
        # 建立与客户端的连接
        client_socket, addr = server_socket.accept()
        print(f"Connected to client: {addr}")

        # 处理客户端请求
        handle_client(client_socket)

    server_socket.close()

if __name__ == '__main__':
    run_server()

# http://127.0.0.1:9090