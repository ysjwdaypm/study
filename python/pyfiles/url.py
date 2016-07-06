

#encoding=utf-8

import urllib,re,os,sys

class URL:
	
	def getHtml(self,path):
		page = urllib.urlopen(path)
		return page.read()

	def getPageImage(self,path):
		reg =  r'src="(.+?\.jpg)"'
		imgre = re.compile(reg)
		htmlinfo = self.getHtml(path)
		#print 'htmlinfo = ',htmlinfo
		imgaelist = re.findall(imgre,htmlinfo)
		
		count = 0
		for image in imgaelist:
			print 'image url = ',image
			urllib.urlretrieve(image,'%s/name_%d.jpg'%(path.split('.')[1],count))
			count+=1

	def downloadInfo(sel,fileDir,infoList):
		for l in infoList:
			l = urllib.unquote(l)
			l = l.replace('\\','')
			print 'path = ',l
			try:
				urllib.urlretrieve(l,'%s/%s'%(fileDir,l.split('/')[-1]))
			except IOError as e:
				print e

	def getPageInfo(self,path,type):
		htmlinfo = self.getHtml(path)

		if type == 'jpg':
			reg1 = r'src="(\S+?\.%s)"'%type
			reg2 = r'"(http://\S+?\.%s)"'%type
			self.downloadInfo(path.split('.')[1],re.findall(re.compile(reg1),htmlinfo))
			self.downloadInfo(path.split('.')[1],re.findall(re.compile(reg2),htmlinfo))
		else:
			reg = r'"(http://\S+?\.%s)"'%type
			self.downloadInfo(path.split('.')[1],re.findall(re.compile(reg),htmlinfo))	


if __name__ == '__main__':
	
	url = URL()
	path = sys.argv[1]
	DIR = path.split('.')[1]
	if not os.path.exists(DIR):
		os.mkdir(DIR)

	url.getPageInfo(path,sys.argv[2])	
	#url.getPageImage(path)				

