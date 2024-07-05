import socket

HOST = '127.0.0.1'  # 服务器 IP 地址 127.0.0.1
PORT = 9090  # 服务器端口号
BUFFER_SIZE = 1024  # 缓冲区大小

def run_client(file_name):
    # 创建客户端套接字
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    client_socket.connect((HOST, PORT))
    print(f"Connected to server: {HOST}:{PORT}")

    # 发送文件名
    client_socket.send(file_name.encode())

    # 接收服务器发送的数据
    response = client_socket.recv(BUFFER_SIZE).decode()

    # 检查是否接收到错误消息
    if response.startswith("File"):
        print(response)
    else:
        # 保存接收到的文件数据
        with open(file_name, 'wb') as file:
            while True:
                data = client_socket.recv(BUFFER_SIZE)
                if not data:
                    break
                file.write(data)

        print(f"File '{file_name}' received successfully")

    client_socket.close()

if __name__ == '__main__':
    file_name = input("Enter the file name: ")
    run_client(file_name)


