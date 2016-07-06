
#include<iostream>

using namespace std;

void log(std::string t1,int t2){
 	cout<<t1<<t2<<endl;
 }

 void log(std::string t1){
 	cout<<t1<<endl;
 }

 void log(char p){
 	cout<<p<<endl;
 }

int ObjectCount = 0;

 class Object{
 public:	
 	int i =12;
 	Object(){
 		ObjectCount++,
 		log("create Object",ObjectCount);
 	};

 	Object(const Object& other){
 		ObjectCount++,
 		log("create Object",ObjectCount);
 	}

 	~Object(){
 		ObjectCount--;
 		log("Delete Object",ObjectCount);
 	};

 	void toString(){
 		log("what can i do for you");
 		int i = 123;
 	};
 };


class Other{
public:
	void toString(){
		log("funk Other");
	}
};

template<class T>
class Base{
public:
	T t;
	Base(T t){
		this->t = t;
	}
	virtual void toString()=0;
};


template<class T>
class Te : public Base<T>{
public:
	Te(T t):Base<T>(t)
	{
	}

	void toString(){
		this->t->toString();
	}
};

// class Circle : public Base{
// public:
// 	void toString(){
// 		log("hahahahhaha");
// 	}
// };

int age = 123;

const int getAge(){
	age = 345;
	return 1;
}

int main(){
	
	// int v = 123;
	// int age=32;
	// int* p = &age;
	// Object* o = new Object();
	// Base* b = new Circle();
	// b->toString();
	// auto fun = [o](){
	// 	// log("fun v = ",v);
	// 	// log("fun age = ",age);
	// 	// log("fun p = ",*p);
	// 	// *p = 456;
	// 	// v=321;
	// 	o->toString();
	// };
	// log("haha");
	// fun();
	// log("v = ",v);
	// log(" age = ",age);
	// log(" p = ",*p);
	// log("haha");
	// Other* other = new Other();
	// Te<Other*>* t = new Te<Other*>(other);
	// t->toString();
	char c = 'y';
	char a = 'a';
	// char * const p = &c;
	// const char* p
	char const * const p = &c;
	// *(p) = 'w';
	log(*p);
	// p = &a;

	int a1 = getAge();
	a1 = 321;
	int i = 0;
	cin>>i;
	log("",i);

	return 0;
}
