# coding=utf-8
__author__ = 'wbsifan'

import json, os, shutil,sys



# 获取所有目录列表
def walkFiles(resPath):
	tree = []
	for item in os.walk(resPath):
		if item[2]:
			for file in item[2]:
				tree.append(os.path.join(item[0], file))
	return tree


def getsize(path):
	size = 0

	for item in walkFiles(path):
		size = size + os.path.getsize(item)

	return str(size)	+ "B"

def compresspng(path):
	print "before compress size = %s"%(getsize(path))
	for item in walkFiles(path):
		if os.path.splitext(item)[1] == ".png":
			os.system("pngquant --speed=1 --ext .png --skip-if-larger --force 256 %s"%item)
			print "compress %s"%item

	print "after compress = %s"%(getsize(path))		

if __name__ == '__main__':
	path = ""
	if len(sys.argv) > 1:
		path = sys.argv[1]

	compresspng(path)	


