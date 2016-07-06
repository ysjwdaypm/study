#encoding:utf-8
import re
import urllib,sys
reload(sys)
sys.setdefaultencoding('utf-8')
 
from collections import deque
 
queue = deque()
visited = set()
 

def saveFile(data,file):
	print 'file = ',file
	f = open('/Users/yons/Documents/tan/webData/' + file,'wb')
	f.write(data)
	f.close()


url = 'http://news.dbanotes.net'  # 入口页面, 可以换成别的
 
cnt = 0

flag = 0


def fenxi(data):
	# 正则表达式提取页面中所有队列, 并判断是否已经访问过, 然后加入待爬队列
	global visited
  	linkre = re.compile('href=\"(.+?)\"')
  	for x in linkre.findall(data):
  		if 'http' in x and x not in visited:
  			queue.append(x)
  			print(' --->  ' + x)

def handlerWeb():

	global visited ,cnt,flag

	url = queue.popleft()
	visited = visited | {url}
	print '已经抓取: ' , str(cnt) , '   正在抓取 <---  ' , url , ' remain ' , str(len(queue))
  	cnt += 1
  	urlop = urllib.urlopen(url)

	if 'html' not in urlop.info().getheader('Content-Type'):
		return False

	try:
		data = urlop.read().decode('utf-8')
		saveFile(data,url.split('/')[-1])
	except Exception as e:
		print e
		return False	

	fenxi(data)
	
			
	return True	     

 
  


if __name__ == '__main__':
	
	if len(sys.argv) == 2:
		url = sys.argv[1]

	queue.append(url)
	while queue:
		handlerWeb()