import socket
#导入socket库

def handle_request(request):
    # 解析HTTP的请求行
    request_lines = request.split("\r\n") #把http请求逐行拆解
    method, path, protocol = request_lines[0].split(" ")  #第一个是请求方法，第二个是请求路径，第三个是协议

    if method != "GET":
        return "HTTP/1.1 405 Method Not Allowed\r\n\r\n"

    # 获取请求的文件
    if path == "/":
        file_path = "./index.html"
    else:
        file_path = "." + path
    #此步骤是为了应对非windowx系统可能无法读取无.的文件

    # 设置一个异常处理
    try:
        with open(file_path, "rb") as file:
            response_body = file.read()
            response_header = "HTTP/1.1 200 OK\r\nContent-Length: {}\r\n\r\n".format(len(response_body))
            return response_header.encode() + response_body
    except FileNotFoundError:
        # return "HTTP/1.1 200 OK\r\nContent-Length: {}\r\n\r\n".format(len(response_body))
        return "HTTP/1.1 404 Not Found\r\n\r\n"


def start_server():
    # 创建TCP套接字，并绑定到本地地址和端口
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_address = ("localhost", 8080)
    server_socket.bind(server_address)

    # 监听客户端连接
    server_socket.listen(1)
    print("Server is listening on {}:{}".format(*server_address))

    while True:
        # 等待客户端连接
        client_socket, client_address = server_socket.accept()
        print("Received connection from {}:{}".format(*client_address))

        # 接收客户端请求
        request = client_socket.recv(1024).decode()
        print("Received request:\n{}".format(request))

        # 处理请求并发送响应
        response = handle_request(request)

        # 如果response是字符串，则转为字节类型
        if isinstance(response, str):
            response = response.encode()

        client_socket.sendall(response)

        # 关闭连接
        client_socket.close()
        # 跳出循环
        break

if __name__ == "__main__":
    start_server()
#检验地址： http://localhost:8080/