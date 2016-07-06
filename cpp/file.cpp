#include <fstream>
#include <iostream>
// #include <stdafx.h>



using namespace std;


void log(string info){
	cout<<info<<endl;
}

template<class T>
T get(T t){
	return t;
}

string getFileContent(string fileName){
	string ss("");
	ifstream in(fileName);
	if(in.is_open()){
		char buffer[256];
		if(!in.eof()){
			in.getline(buffer,256);
			ss += buffer;
		}

		in.close();
	}

	return ss;
}

void writeToFile(string fileName,string info,bool append=false){
	string oldinfo("");
	if(append){
		oldinfo = getFileContent(fileName);
		// log("oldinfo = " + oldinfo);
	}

	ofstream out(fileName);
	if(out.is_open()){
		out<<oldinfo<<info<<endl;
		out.close();
		// log("write successfully = " + info);
	}
}

int main(int argc,char** argv){

	string fileName("out.txt");
	writeToFile(fileName,*(argv + 1));
	log("-------------------------------------------------");
	log(getFileContent(fileName));
	string t = "123";
	log(get(t));
	return 0;
}