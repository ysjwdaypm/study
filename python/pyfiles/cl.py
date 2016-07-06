if __name__ == '__main__':
    import socket

    sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
    sock.connect(('localhost',8012))

    while True:
        info = input('write:\n')
        sock.send(info)
        print 'server: ',sock.recv(1024)

    sock.close()