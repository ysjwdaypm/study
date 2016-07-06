
#include <pthread.h>
#include <stdio.h>



void * mainLoop(void* data){
	//printf("%s\n", data);
	printf("1222222\n");
	char ch;
	while((ch = getchar()) != '\0'){
		printf("input %c\n", ch);
	}
}

int main(int argc, char const *argv[])
{
	
	pthread_t th;
	void* retval;
	pthread_create(&th,NULL,mainLoop,0);
	pthread_join(th,&retval);	
	return 0;
}