#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include "func.c"
#include <arpa/inet.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <pthread.h>
// #include <thread.h>

// #pragma message("hello world")
// #pragma warning("error:154")

// extern int MONEY;
// extern int DAY;

// int MAX(int a,int b){
// 	return a < b?a:b;
// }

#define set_s(x,y) {strcpy(s[x].name,y);s[x].size=strlen(y);}
#define nmemb 3

struct test
{
	char name[20];
	int size;
}s[nmemb];


int sfd;
struct sockaddr_in my_addr;

int clientSfd;

int current = 0;
int clientS[1024] = {0};


void addClient(int id){
	clientS[current++] = id;
}

void removeClient(int id){
	int i = 0;
	int find = -1;
	for(;i<current;i++){
		int cfd = clientS[i];
		if(cfd == id){
			find = 1;
			break;
		}
	}
	if(find == 1){
		for(int k = i;k<current-1;k++){
			clientS[i] = clientS[i+1];
		}
		current--;
	}
	
}


void broadcastMessage(char* info,int fromId,int charSize){
	// printf("start broadcastMessage current = %d fromId = %d\n", current,fromId);
	for(int i=0;i<current;i++){
		int cfd = clientS[i];
		// printf("check cfd = %d\n",cfd);
		if(cfd != -1){
			
			int len = send(cfd,info,charSize,0);
			printf("broadcastMessage %s to clientId %d,total %d chars ,but only send %d char\n",info,cfd,charSize,len);
		}
	}
}

void* clientThread(void* data){
	int cfd = *((int*)data);
	int len = -1;
	char info[1024];
	while((len = recv(cfd,info,sizeof(info),0)) > 0){
		info[len] = '\0';
		if(strcmp(info,"end") == 0){
			printf("close client %d\n",cfd);
			removeClient(cfd);

			break;
		}
		else
		{
			broadcastMessage(info,cfd,len);
			printf("get message from client is %s\n",info);
			
		}
	}

	printf("close client = %d\n", cfd);
	return 0;
}

void createClientThread(int cfd){

	addClient(cfd);

	pthread_t th;
	// void* retval;
	pthread_create(&th,NULL,clientThread,(void*)&cfd);
	// pthread_join(th,&retval);
	pthread_detach(th);
	printf("create client thread complete\n");
}


int main(){
	printf("starting server\n");
	sfd = socket(AF_INET,SOCK_STREAM,0);
	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons(8013);
	// my_addr.sin_addr.s_addr = inet_addr("127.168.1.1");
	my_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	memset(&(my_addr.sin_zero),0,sizeof(my_addr.sin_zero));
	bind(sfd,(struct sockaddr *)&my_addr,sizeof(struct sockaddr_in));
	listen(sfd,1);
	printf("wait for client\n");
	

	while(true){
		printf("handler accept\n");
		struct sockaddr_in other_addr;
		int size = sizeof(struct sockaddr_in);
		int cfd = accept(sfd,(struct sockaddr *)&other_addr,(socklen_t *)&size);
		printf("eccept clientId is %d\n", cfd);
		if(cfd != -1){
			printf("connect me ip is  %s, clientId = %d\n", inet_ntoa(other_addr.sin_addr),cfd);
			char* info = (char*)"welcometomyworld";
			send(cfd,info,sizeof(info),0);
			createClientThread(cfd);
		}
		
	}

	printf("finished server\n");
	// int clientSfd = accept(sfd,(struct sockaddr *)&other_addr,(socklen_t *)&size);
	// if(clientSfd != -1){
	// 	printf("connect me ip is %s\n", inet_ntoa(other_addr.sin_addr));
	// 	char* info = "welcome to my world";
	// 	send(clientSfd,info,sizeof(info),0);
	// 	createClientThread(clientSfd);
	// 	// int len = -1;
	// 	// // int BUFSIZ = 1024;
	// 	// char buf[BUFSIZ];  //数据传送的缓冲区 
	// 	// while((len = recv(clientSfd,buf,BUFSIZ,0)) > 0){
	// 	// 	buf[len] = '\0';
	// 	// 	if(strcmp(buf,"end") == 0){
	// 	// 		printf("end application\n");
	// 	// 		break;
	// 	// 	}
	// 	// 	else
	// 	// 	{
	// 	// 		printf("get message from client is %s\n",buf);
	// 	// 	}
	// 	// }
	// }
	// else
	// {
	// 	printf("connect failed\n");
	// }


}




int main1(int argc,char* argv[]){

printf("parmas count = %d\n", argc);
for(int i=0;i<argc;i++){
	printf("%s\n", argv[i]);
}

// 	printf("abc\tde\n");
// 	printf("1234567898765432101234\n");
// 	printf("h\ti\b\bj k\n");
// 	printf("haha\r.mx\n");
// 	printf("hello world\a\n");
// 	// printf("\ty\ts\n");
// 	printf(3>2?"y\n":"us");
// 	printf("%d\n", 3*4/2+12-1);

// int x,y=7;
// float z=4;
// x = (y=y+6,y/z);
// printf("x  = %d, y = %d\n", x,y);
// printf("error info is %s\n", strerror(errno));

// float a,b;
// scanf("a=%f,b=%f",&a,&b);
// printf("you put a=%f b= %f\n", a,b);


// int arr[10][10];
// arr[0][0] = 1;
// arr[1][0] = arr[1][1] = 1;
// for(int i=2;i < 10;i++){

// 	for(int j= 0;j<=i;j++){
// 		int n = j==0||j==(i)?(1):(arr[i-1][j-1] + arr[i-1][j]);
// 		arr[i][j] = n;
// 		printf("%4d  ",n);
// 	}
// 	printf("\n");

// }


// 	long int f1,f2;
// 	f1=1;f2=1;
// 	for(int i=1;i<=20;i++){
// 		printf("%12ld %12ld", f1,f2);
// 		if(i%2==0)printf("\n");
// 		f1=f1+f2;
// 		f2=f2+f1;
// 	}

// 	int a;
// 	// scanf("%d",&a);
// 	// if(a < 100){
// 	// 	printf("less 100\n");
// 	// }else{
// 	// 	printf("than 100\n");
// 	// }
// 	puts("i love \n china");
// 	puts("haha");

// // int aa[][10];
// float f[][2] = {1.1f,1.2f,1.3f,1.4f,1.5f};
// printf("%7.2f\n", f[2][0]);

// printf("sum(12,23) = %d\n", sum(12,23));

// auto u = 1233;
// register long ii=123;
// printf("ii = %ld\n", u);

// printf("money = %d\n", MONEY);
// printf("MAX(12,34) = %d\n", MAX(12,34));


// FILE* p = fopen("config.txt","r+");

// if(p != NULL){
// 	// fprintf(p, "%s\n");
// 	char info[1024] = {0};
// 	while(fgets(info,1024,p) != 0){
// 		printf("current file position is %d\n", ftell(p));
// 		printf("%s", info);
// 	}
// }else
// {
// 	printf("open file config.txt failed\n");
// }


// FILE* fp = fopen("temp.json","w+");
// if(fp != NULL){
// 	fputs("ysjwda",fp);
// 	fclose(fp);
// }



FILE * stream;
// set_s(0,"Linux!");
// set_s(1,"FreeBSD!");
// set_s(2,"Windows2000.");
stream=fopen("temp.json","r");
fwrite(s,sizeof(struct test),nmemb,stream);
// fclose(stream);
fread(s,sizeof(struct test),nmemb,stream);
fclose(stream);
for(int i=0;i<nmemb;i++)
printf("name[%d]=%-20s:size[%d]=%d\n",i,s[i].name,i,s[i].size);

struct sockaddr_in s_in;

s_in.sin_addr.s_addr = inet_addr("192.168.1.1");
printf("net = %d\n", s_in.sin_addr.s_addr);
printf("net s %s\n", inet_ntoa(s_in.sin_addr));
// htonl()
	exit(0);

}


//fab c   de      
//h       jk
//6 + 12-1