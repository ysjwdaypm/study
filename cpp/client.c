

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/socket.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <errno.h>

#include <pthread.h>


void* revcFromServer(void* data){
	int cfd =*((int*)data);
	int len = -1;

	char buf[1024];
	while((len = recv(cfd,buf,sizeof(buf),0)))
	{
		if(len > 0){
			buf[len] = '\0';
			printf("get message from server is %s     and len = %d\n", buf,len);
		}else
		{
			if(len != 0){
				printf("len = %d , error %s\n", len,strerror(errno));
			}
			else
			{
				printf("-----------------------------------\n");
			}
		}
	}
	
	
}

void startThread(int cfd){
	pthread_t th;

	pthread_create(&th,NULL,revcFromServer,(void*)&cfd);

	pthread_detach(th);
}


int main(){


	

	int sfd = socket(AF_INET,SOCK_STREAM,0);
	if(sfd != -1){
		struct sockaddr_in my_addr;
		my_addr.sin_family = AF_INET;
		my_addr.sin_port = htons(8013);
		my_addr.sin_addr.s_addr = inet_addr("192.168.1.24");
		memset(&(my_addr.sin_zero),0,sizeof(my_addr.sin_zero));

		int ret = connect(sfd,(struct sockaddr*)&my_addr,sizeof(struct sockaddr_in));
		if(ret != -1){
			printf("connect server success ret = %d!\n",ret);
			char info[1024] = {0};
			// int len = -1;


			startThread(sfd);

			while(gets(info)){

				int len = 0;
				while(info[len] != 0){
					len++;
				}
				int ret = send(sfd,info,len,0);
				if(ret != -1){
					info[len] = '\0';
					printf("send info is %s     len = %d , ret = %d\n", info,len,ret);
				
					if(strcmp(info,"end") == 0){
						break;
					}
				}
				else
				{
					printf("send error %s\n", strerror(errno));
					break;
				}


				

				// memset(info,0,1024);
			}
		}else{
			printf("connect server failed %s!\n",strerror(errno));
		}
	}
}

