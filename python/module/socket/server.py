import threading


socketlist = []


def brodbast(msg):
	for s in socketlist:
		s.send(msg)

def getData(conn):
	while True:
		d = conn.recv(1024)
		if len(d) < 7:
			print "remove client------"
			socketlist.remove(conn)
			break
		else:
			# conn.send("server say:" + d)
			brodbast(d)



if __name__ == "__main__":

	import socket
	sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
	sock.bind(('localhost',8001))
	sock.listen(100)

	while True:
		conn,address = sock.accept()
		try:
			# conn.settimeout(5)
			# getData(conn)
			t = threading.Thread(target=getData,args=(conn,))
			t.setDaemon(True)
			t.start()

			socketlist.append(conn)
			# buf = conn.recv(1024)
			# if buf =="1":
			# 	conn.send("welcome to server!")
			# else:
			# 	conn.send("please go out!")
		except socket.timeout:
			print "time out"
		# conn.close()
