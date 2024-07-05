import socket


def send_dns_query(dns_server, dns_query):
    # 创建UDP socket
    client_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # 发送DNS请求报文
    client_socket.sendto(dns_query, (dns_server, 53))
    response, address = client_socket.recvfrom(1024)

    # 关闭socket
    client_socket.close()
    return response, address



def receive_dns_response():
    # 创建UDP socket
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)

    # 绑定本地地址和端口
    server_socket.bind(("0.0.0.0", 53))

    # 接收DNS响应报文
    response, address = server_socket.recvfrom(1024)

    # 关闭socket
    server_socket.close()

    return response, address


def dns_request(domain, dns_server):
    # 创建UDP套接字
    sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
    sock.settimeout(5)  # 设置超时时间

    # DNS服务器地址和端口
    # dns_addr = (dns_server, 53)

    # 构建DNS请求
    transaction_id = 1234  # 事务ID，可以随机生成
    flags = 0x0100  # 标志位，表示查询
    question_count = 1  # 问题计数

    # 构建问题部分
    qname = domain.encode()  # 域名转换为字节串
    qtype = 1  # 查询类型为A记录
    qclass = 1  # 查询类别为IN

    # 构建DNS请求报文
    dns_query = transaction_id.to_bytes(2, byteorder='big') + \
                flags.to_bytes(2, byteorder='big') + \
                question_count.to_bytes(2, byteorder='big') + \
                b'\x00\x00\x00\x00\x00\x00' + \
                qname + \
                qtype.to_bytes(2, byteorder='big') + \
                qclass.to_bytes(2, byteorder='big')

    try:
        # 发送DNS请求到DNS服务器
        data, addr = send_dns_query(dns_server, dns_query)

        # 接收DNS响应
        # data, addr = receive_dns_response()

        # 处理DNS响应
        # 这里可以根据DNS协议解析data，并提取出回答部分的信息

        print(f"Received DNS response from {addr}:")
        print(data)

    except socket.timeout:
        print("DNS request timed out.")


# 示例调用
domain = "www.baidu.com"  # 查询的域名
dns_server = "192.168.247.6"  # DNS服务器地址

dns_request(domain, dns_server)