import socket
import os

SERVER_HOST = "localhost"
SERVER_PORT = 12348
BUFFER_SIZE = 4096

def send_file(conn, filename):
    filesize = os.path.getsize(filename)
    conn.sendall(str(filesize).encode())
    with open(filename, "rb") as f:
        while True:
            data = f.read(BUFFER_SIZE)
            if not data:
                break
            conn.sendall(data)

def main():
    server_socket = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
    server_socket.bind((SERVER_HOST, SERVER_PORT))
    server_socket.listen(1)
    print(f"[*] Listening on {SERVER_HOST}:{SERVER_PORT}")

    while True:
        conn, addr = server_socket.accept()
        print(f"[*] Accepted connection from {addr[0]}:{addr[1]}")

        filename = conn.recv(BUFFER_SIZE).decode()
        if os.path.isfile(filename):
            print(f"[*] Sending {filename} to {addr[0]}:{addr[1]}")
            conn.sendall(b"EXIST")
            send_file(conn, filename)
        else:
            print(f"[!] File {filename} does not exist!")
            conn.sendall(b"ERROR")

        conn.close()
        print(f"[*] Connection closed with {addr[0]}:{addr[1]}")

if __name__ == "__main__":
    main()