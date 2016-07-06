import os,sys

def main(file):
	os.system('clang -Wall -g -std=c++11  -lstdc++ -stdlib=libc++ -o %s %s.cpp'%(file,file))
	os.system('./%s'%(file))

if __name__ == '__main__':

	if len(sys.argv) > 1:
		main(sys.argv[1])