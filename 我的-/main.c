#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
void main(int argc,char *argv[])
{
	int fd=0;
	sscanf(argv[1],"%d",&fd);
	char b[128]={0};
	while(1)
	{
		int n=read(fd,b,3);
		if(n==0)
		{
			break;
		}
	printf("%s",b);
	}
//	printf("\n");
    close(fd);
	printf("main is over\n");
}
