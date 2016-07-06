#coding=utf-8

import os,sys

# 获取所有目录列表
def walkFiles(resPath):
	tree = []
	for item in os.walk(resPath):
		if item[2]:
			for file in item[2]:
				tree.append(os.path.join(item[0], file))
	return tree

def main(path,match):
	searchlist = []
	for file in walkFiles(path):
		if match in file:
			searchlist.append(file)
		else:	
			f = open(file,'r')
			d = f.read()
			if not d.find(match) == -1:
				searchlist.append(file)
			f.close()

	print "result:\n" + ("\n").join(searchlist)			

if __name__ == '__main__':
	p = ""
	match = ""
	if len(sys.argv) > 2:
		p = sys.argv[1]
		match = sys.argv[2]
	main(p,match)