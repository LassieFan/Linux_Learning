#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<signal.h>
#include<assert.h>
void fun(int sig)
{
	wait(NULL);	
	printf("signal coming\n");
}
void main()
{
	pid_t pid=fork();
	assert(pid!=-1);
	if(pid==0)
	{
        printf("child go on\n");
	    sleep(10);
		printf("child over\n");
	}
	else
	{
        signal(SIGCHLD,fun);
	   	printf("father go on\n");
		sleep(20);
        sleep(2);
		printf("father over\n");
	}
}
