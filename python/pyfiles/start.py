#encoding=utf-8

import os,sys

# >>> x = 3
# >>> 1 < x < 5
# True
# >>> 4 > x >=3
# True

# def foo(x, y):
# print x, y

# alist = [1, 2]
# adict = {'x': 1, 'y': 2}
# foo(*alist) # 1, 2
# foo(**adict) # 1, 2

class L0001:
	def foo(l=[]):
		l.append(1)
		print l

	def __init__(self):
		foo()
		foo()



class L0002:

	def __init__(self):
		self.test()

	def test(self):
		print "hello %(name)s"%{"name":"ysjwdaypm"}
		print "I am years %(age)i years old" % {'age': 18}
		print "Hello {name} !".format(name="James")


class L0003:

	def __init__(self):

		dct = {}

		dct["name"] = dct.get("name","ysj")
		print dct	

class L0004:

	def __init__(self):
		"""
		else语句块会在循环结束后执行，除非在循环块中执行break
		"""

		for i in (1,3,5,6):
			if i % 2 == 0:
				break
		else:
			print "var i is always an odd"


"""
 dict 的特殊方法__missing__
Python 2.5之后引入的。当查找不到key的时候，会执行这个方法。
>>> class Dict(dict):
... def __missing__(self, key):
... self[key] = []
... return self[key]
...
>>> dct = Dict()
>>> dct["foo"].append(1)
>>> dct["foo"].append(2)
>>> dct["foo"]
[1, 2]
这很像collections.defaultdict不是吗?
>>> from collections import defaultdict
>>> dct = defaultdict(list)
>>> dct["foo"]
[]
>>> dct["bar"].append("Hello")
>>> dct
defaultdict(<type 'list'>, {'foo': [], 'bar': ['Hello']})
"""
class Dict(dict):
	
	def __missing__(self,key):
		self[key] = []
		print " srarch key is %s"%key
		return self[key]	


class L0005:

	def __init__(self):
		
		dct = Dict()
		dct["foo"].append(1)
		print dct["foo"]
		print [x + 2 for x in range(10)]
		# l = lambda x,y:x * (x + y) / (x - y)
		print l(23,45)


"""
使用lambda函数应该注意的几点：

lambda定义的是单行函数，如果需要复杂的函数，应该定义普通函数
lambda参数列表可以包含多个参数，如 lambda x, y: x + y
lambda中的表达式不能含有命令，而且只限一条表达式
"""
class L0006:

	def __init__(self):
		
		print self.createMethod(10)(100)

		print [self.createMethod(x)(100) for x in xrange(10,0,-1)]


	def createMethod(self,x):
		return lambda y: x * (x + y) / (x - y)	


class L0007:

	def __init__(self):
		
		# print "ysj"*100 + "end"

		"""
		计算字符个数
		"""
		# print "ysjwdaypm".count('y')
		# b = lambda x,y : sys.stdout.write(x[0]) or len(x) != 1 and y( (x[1:]+x[1])[1:] , y) 
		"""
		迭代调用
		f = lambda x,y : sys.stdout.write(x[0]) or len(x) != 1 and y( (x[1:]+x[1])[1:] ,y) 
		(lambda a,b = f : b(a,b) ) ('47041037')
		"""
		(lambda a,b = lambda x,y : (sys.stdout.write(x[0] + '--------' + x  + '\n')) or len(x) != 1 and y( (x[1:]+x[1])[1:] , y) : b(a,b) ) ('47041037')
		x = '47041037'
		# sys.stdout.write('47'[0])
		# print (x[1:]+x[1])[1:]

"""
"""
# L0001()
# L0002()
# L0003()
# L0004()
# L0005()
# L0006()
# L0007()

txt = '/Users/yons/Documents/tan/projects/branches/sdkBranch/hope/music.txt'

f = open(txt,"wb")
infoList = [];
saveinfo = ""
totalSize = 0
for item in os.walk('/Users/yons/Documents/tan/projects/branches/sdkBranch/hope/res'):
	if not item[2]:
		continue

	for file in item[2]:
		ext = os.path.splitext(file)[-1]
		# print "ext = ",ext
		if ext == ".mp3" or ext == ".m4a":
			path = os.path.join(item[0],file)
			name =  path.replace('/Users/yons/Documents/tan/projects/branches/sdkBranch/hope/res','')
			size =  os.path.getsize(path)
			totalSize = totalSize + size
			kb = size / 1024
			infoList.append([name,size,kb])
			# saveinfo = saveinfo + "%s    size = %dbyte %dkb\n"%(name,size,kb)		


# infoList = sorted(infoList, reverse=True,key = lambda info : info[2])
# reverse = True
f.write('totalSize = %dkb\n'%(totalSize / 1024) + ''.join(["%s\tsize = %dbyte\t%dkb\n"%(info[0],info[1],info[2]) for info in sorted(infoList, reverse=True,key = lambda info : info[2])]))
# totalSize = totalSize / 1024
# saveinfo = 'totalSize = %d\n'%totalSize.join(["%s\t\t\t\tsize = %dbyte \t\t%dkb\n"%(info[0],info[1],info[2]) for info in infoList])
# for info in infoList:
# 	saveinfo = saveinfo + "%s\t\t\t\tsize = %dbyte \t\t%dkb\n"%(info[0],info[1],info[2])
# f.write(saveinfo)
f.close()			
os.system('open %s'%txt)
