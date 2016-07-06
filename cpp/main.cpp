#include<iostream>
#include<vector>
#include<map>
#include<sstream>
#include<thread>
#include<mutex>
using namespace std;

class Object{
public:
	int age; // 4
	// char c;
	int height;//4
	int wwight;//4
	int w;
	char c;
	// char c;
	// char cc;
	// char ccc;
	// char cccc;
	// char x;
	// char ccccc;
	string name;//24

	// void test(){

 // 	}
};


void show(){

}
/*
 int---->4
 int*--->8
 char--->1  {'y'}有几个是几个  "ysj" strlen() + 1
 char*-->8		
 string->24

 float--->4
 double--->8

 std::function(void) ----->48

 *----->8
*/

// void log(int t){
// 	cout<<t<<endl;
// }

// void log(string t){
// 	cout<<t<<endl;
// }

 void log(std::string t1,int t2){
 	cout<<t1<<t2<<endl;
 }


template<class T>
 void log(T t1){
 	cout<<t1<<endl;
 }


template<class T>
class Test
{
private:
	T t;
public:
	Test(T t)
	{
		this->t = t;
	}
	~Test(){

	}

	void toString(){
		cout<<t<<endl;
	}

	/* data */
};


int i = 0;
mutex m;

void threadFun(){
	m.lock();
	// log(this_thread::get_id());
	i++;
	this_thread::sleep_for(chrono::seconds(1));
	log(this_thread::get_id());
	log(i);
	m.unlock();
}

void testThread()
{
	std::vector<std::thread*> threads;
	for (int i = 0; i < 5; ++i)
	{
		threads.push_back(new std::thread(threadFun));
	}

	for(auto th : threads){
		th->join();
	}

    int v = 123;
	auto fun = [v](){
		log("haha");
        log("v=",v);
	};

	fun();
	
}


#include<condition_variable> 
condition_variable cv;
condition_variable cvP;
condition_variable cvS;

mutex ms,mp;


int apple = 0;

int totalEatApple = 0;
bool complete = false;

void eatApple(int n){
	for (int i = 0; i < n; ++i)
	{
		/* code */
		log("eat apple ",apple);
		apple--;
		totalEatApple++;
		if(totalEatApple >= 2*n)
			complete = true;
		log("totoal eat apple is ",totalEatApple);
		this_thread::sleep_for(chrono::seconds(1));
	}
}

void com(int n){

	while(!complete){
		{
			unique_lock<mutex> lck(mp);
			if(apple<1)
				cvP.wait(lck);

			eatApple(n);
		}

		//{
			unique_lock<mutex> lck2(ms);
			cvS.notify_one();
		//}
	}
	// com(n);
}


void createApple(int n){
	for (int i = 0; i < n; ++i)
	{
		log("get apple ",apple);
		this_thread::sleep_for(chrono::seconds(1));
		apple++;
	}
}

void pro(int n){
	while(!complete){
		//{
			unique_lock<mutex> lck(ms);
		if(apple > 0)
			cvS.wait(lck);
		if(complete)break;

		createApple(n);
		//}

		//{
			unique_lock<mutex> lck2(mp);
			cvP.notify_one();
		//}
	}
	// {
	// 	unique_lock<mutex> lck(ms);
	// 	while(apple>0)
	// 		cvS.wait(lck);

	// 	createApple(n);
	// }

	// // pro(n);	
	
	// 	{
	// 		unique_lock<mutex> lck2(mp);
	// 		if(apple == n)
	// 		{
	// 			cvP.notify_one();
	// 		}

	// 	}
	
}


void test3(){
	thread c = thread(com,5);
	thread p = thread(pro,5);
	c.join();
	p.join();

}

bool ready = false;

void printTest(int i){
	unique_lock<mutex> lck(m);
	while(!ready)
		cv.wait(lck);

	log(i);
	this_thread::sleep_for(chrono::seconds(1));
}


void go(){
	// unique_lock<mutex> lck(m);
	ready = true;
	cv.notify_all();
}
void lockThread(){

	std::vector<thread> l;

	for (int i = 0; i < 10; ++i)
	{
		/* code */
		l.push_back(thread(printTest,i));
	}
	// go();
	{unique_lock<mutex> lck(m);
	ready = true;
	cv.notify_all();}
	for(auto& t : l){
		t.join();
	}

}


int num = 0;

bool getCount(){return num != 0;}

void consumer(int n){
	log("--------------------------");
	for (int i = 0; i < n; ++i)
	{
		unique_lock<mutex> lck(m);
		cv.wait(lck,getCount);
		log(num);
		num = 0;
	}
}

void test2(){

thread consumerThead(consumer,10);


for (int i = 0; i < 10; ++i)
{
	while(getCount())
		this_thread::yield();

	unique_lock<mutex> lck(m);
	num = i + 1;
	cv.notify_one();
}

consumerThead.join();

}



void staticTest(){
	static int count = 0;
	printf("%d\n", count);
	count++;
}

int main(){

	// staticTest();
	// staticTest();
	// staticTest();

	 string in = "ysj";
	//char in[4] = {'y','y'};
	char* cl = (char*)"ysj";
	// int count = 0;
	// while(*cl != '\0'){
	// 	log(*cl++);
	// 	count++;
	// }
	// log("--------------------------");
	// log(count);
	log("--------------------------");
	cl += 45;
	stringstream strs;
	while(*cl != '\0'){
		strs<<*cl++;
		// count++;
	}
	log(strs.str());

	// char t[] = {'y','w','b'};
	log("--------------------------");
	log(in.size());
	log(in.length());
	// log(sizeof(17));
	// test3();
//	lockThread();
	// sleep(4);
	// ready = true;
	// cv.notify_all();

	// Test<char> c('y');
	// c.toString();


	// Test<int> i(123);
	// i.toString();

	// Test<string> s("ysjwdaypm");
	// s.toString();

	// Test<long> l(1234);
	// l.toString();

	// Test<short> si(787);
	// si.toString();
	// cout<<"hello world!"<<endl;
	// const type_info* p = &typeid(Object);
	// cout << p->name() << endl << "size = "<< sizeof(p)<<endl;
	// char c = 'h';
	// cout<<"char*c = "<<sizeof(c)<<endl;
	// int i = 1234567;
	// cout<<"int i= 1234567  "<<sizeof(i)<<endl;
	// char cl[] = {'y','w'};
	// cout<<"char[]cl = "<<sizeof(cl)<<endl;

	// Object* o = new Object();
	// cout<<"o "<<sizeof(o)<<endl;


	// char _name[] = "ysj";
	// cout<<"len(name) = "<<sizeof(_name)<<endl<<strlen(_name)<<endl;

	// std::function<void()> fun = &show;
	// cout<<"function = "<<sizeof(fun)<<endl;

	// Object oo = *o;
	// cout<<"oo "<<sizeof(oo)<<endl;
	// cout<<"string "<<sizeof(string)<<endl;
	
	// int list[] = {1,2,3,4,5,6};
	// std::vector<char> v;
	// v.push_back('y');

	// for(auto id : v){
	// 	int test = 2;
	// 	cout<<id<<endl;
	// }
	//  log(12);
	//  int price = 0;
	//  stringstream("12345")>>price;
	//  stringstream strem;
	//  strem<<"123"<<"syh"<<123;
	//  log(strem.str());

	  // char buff[20];
	  // cin.getline(buff,20);
	  // log(buff);

	return 0;
}
