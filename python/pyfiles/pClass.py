#encoding=utf-8

class T:

	def __init__(self,name):
		self.name = name


	def __len__(self):
		print "show T->len function"
		return 1

	def __str__(self):
		return "my name is %s"%self.name

	def __del__(self):
		# print __FILE__
		# print __FUNCTION__
		print "del......... ",self.name	

	def fun(self):
		try:
			print "12"
		except NameError:
			print e
		finally:
			print "yes"	

	def __getitem__(self,key):
		print 'return key = ',key
		return 'test'	

	def __lt__(self,other):
		print 'self.name = ',self.name ,"  other name = ",other.name
		return True




	
if __name__ == '__main__':
	
	t = T("ysjwdaypm")
	print len(t)
	print str(t)
	print t['name']
	t.fun()

	print '-----------------------------'
	print t < T('12')
