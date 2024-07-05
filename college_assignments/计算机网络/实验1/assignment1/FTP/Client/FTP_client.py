import socket

SERVER_HOST = "localhost"
SERVER_PORT = 12348
BUFFER_SIZE = 4096

def receive_file(conn, filename):
    with open(filename, "wb") as f:
        while True:
            data = conn.recv(BUFFER_SIZE)
            if not data:
                break
            f.write(data)

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.connect((SERVER_HOST, SERVER_PORT))

    filename = input("Enter the filename to download: ")
    server_socket.sendall(filename.encode())

    response = server_socket.recv(BUFFER_SIZE).decode()
    if response == "EXIST":
        print(f"[*] Receiving {filename}")
        receive_file(server_socket, filename)
        print(f"[*] File {filename} received successfully!")
    else:
        print(f"[!] Error: File {filename} does not exist!")

    server_socket.close()

if __name__ == "__main__":
    main()