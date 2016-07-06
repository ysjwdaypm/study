#encoding=utf-8

if __name__ == '__main__':


    def handle(so):
        while True:
            info = so.recv(1024)
            if info.strip():
                print 'client:' ,info
                so.send(info)
            else:
                print 'disconnect'
                break
        so.close()

    import socket
    sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)

    sock.bind( ('localhost',8012))
    sock.listen(100)
    while True:
        con,address = sock.accept()

        try:
            con.settimeout(None)
            handle(con)
        except socket.timeout:
            print 'time out'

#con.close()



