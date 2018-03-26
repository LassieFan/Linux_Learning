#include<stdio.h>
#include<sys/types.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<assert.h>
int main()
{
   int fd[2]={0};
   if(-1==pipe(fd))
   {
	   printf("error\n");
	   exit(0);
   }
   pid_t res=fork();
   assert(res!=-1);
   if(0==res)
   {
       close(fd[1]);
       while(1)
	   {
		   char buff[128]={0};
		   int n=read(fd[0],buff,127);
		   if(0==n)
		   {
			   exit(0);
		   }
		   int i=n-1;
		   for(;i>=0;i--)
		   {
			   printf("%c",buff[i]);
		   }
		   printf("\n");
	   }
	   close(fd[2]);

   }
   else
   {
       close(fd[0]);
	   while(1)
	   {
		   char buff[128]={0};
		   printf("please input the string:");
		   fgets(buff,127,stdin);
		   buff[strlen(buff)-1]=0;
		   if(strncmp(buff,"end",3)==0)
		   {
			   exit(0);
		   }
		   write(fd[1],buff,strlen(buff));
		   sleep(1);
	   }
	   close(fd[1]);
   }
}
