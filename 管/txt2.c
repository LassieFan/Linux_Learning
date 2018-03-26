#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<assert.h>
int main(int argc,char *argv[])
{
	int fd=open("FIFO",O_RDONLY);
	if(fd==-1)
	{
    	int m=mkfifo("FIFO",0664);
		if(m==-1)
		{
			perror("FIFO");
			exit(0);
		}
		fd=open("FIFO",O_RDONLY);
	}
	assert(fd!=-1);
	int fd1=open(argv[1],O_WRONLY|O_CREAT,0664);
	assert(fd1!=-1);
	while(1)
	{
        char buff[128]={0};
        int n=read(fd,buff,127);
		if(n==0)
		{
			exit(0);
		}
        write(fd1,buff,n);
	}
	close(fd);
	close(fd1);
}	
