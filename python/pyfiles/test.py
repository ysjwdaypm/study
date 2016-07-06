#encoding=utf-8


import Tkinter,tkMessageBox

top = Tkinter.Tk()
label = Tkinter.Text(top)

def clickBtn():
	tkMessageBox.showinfo("123","456")
	print label.get('1.0','10.0')


def showGUI():
	btn = Tkinter.Button(top,text=u'你不知道你是谁吗',command=clickBtn)
	btn.pack()
	#label.tag_add('123','1.0','1.4')
	label.pack()
	top.mainloop()

def showThread():
	import os

	print os.path

	from time import ctime,sleep
	import time

	print time.time()

	if True:
		print 'what you want'



	def music(func):
		for i in range(2):
			print " i was listening to %s . %s"%(func,ctime())
			sleep(1)

	def movie(func):
		for i in range(2):
			print "i was at the %s. %s"%(func,ctime())
			sleep(1)

	import threading
	
	threads = []

	t1 = threading.Thread(target=music,args=(u'爱情买',))
	threads.append(t1)

	t2 = threading.Thread(target=movie,args=(u'你是谁',))
	threads.append(t2)

	#music('123')
	#movie('456')

	for t in threads:
		print "execute thread method"
		t.setDaemon(True)
		t.start()
	t.join()


	print "over time ",ctime()	

	import thread

	thread.start_new_thread(music,('123',))

	print 'end process'

if __name__ == '__main__':

	showGUI()
