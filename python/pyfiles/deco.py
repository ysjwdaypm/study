

"""
问题：
     Python的函数定义中有两种特殊的情况，即出现*，**的形式。
     如：def myfun1(username, *keys)或def myfun2(username, **keys)等。

解释：
  * 用来传递任意个无名字参数，这些参数会一个Tuple的形式访问。

   **用来处理传递任意个有名字的参数，这些参数用dict来访问。*
"""

def deco(fun):
	def inner(*args,**kwargs):
		return fun(*args,**kwargs)
	return inner

@deco
def my_func(*args):
	print(args)

my_func(1,2,3)		