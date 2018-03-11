#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<assert.h>
void main()
{
	int fd=open("a.txt",O_RDONLY);
	assert(fd!=-1);
	char b[128]={0};
	sprintf(b,"%d",fd);
	printf("%s\n",b);
	printf("execl is coming\n");
	execl("./main","main",b,NULL);
	printf("execl is error\n");
}
