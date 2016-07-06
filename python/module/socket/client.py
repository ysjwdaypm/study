
import threading,os


name = ""

def getData():
	while True:
		d = sock.recv(1024)
		d = d.replace('\n',"         ")
		print "" + d
		os.system('say %s'%d)


if __name__ == "__main__":

	import socket,sys

	if len(sys.argv) > 1:
		name = sys.argv[1]
	else:
		name = "default"	

	sock = socket.socket(socket.AF_INET,socket.SOCK_STREAM)
	sock.connect(('localhost',8001))
	# sock.settimeout(None)
	
	t = threading.Thread(target=getData)
	t.setDaemon(True)
	t.start()

	while True:
		d = raw_input("input you message\n")
		f = open('s.txt','r')
		sock.send(name + ":" + d)
		f.close()
