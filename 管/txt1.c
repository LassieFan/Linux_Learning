#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<assert.h>
int main()
{
	int fd=open("FIFO",O_WRONLY);
	if(fd==-1)
	{
    	int m=mkfifo("FIFO",0664);
		if(m==-1)
		{
			perror("FIFO");
			exit(0);
		}
		fd=open("FIFO",O_WRONLY);
	}
	assert(fd!=-1);
	while(1)
	{
		printf("please inpute the data: ");
		char buff[128]={0};
		fgets(buff,127,stdin);
		if(strncmp(buff,"end",3)==0)
		{
			exit(0);
		}
		write(fd,buff,strlen(buff)-1);		
	}
	close(fd);
}	
