#include<stdio.h>
#include<sys/types.h>
#include<fcntl.h>
#include<assert.h>
#include<unistd.h>
int main()
{
   int fd=open("c.txt",O_RDONLY);
   assert(fd!=-1);
   pid_t pid=fork();
   assert(pid!=-1);
  if(pid!=0)
  {
    char c;
    while(1) 
   {
      int n=read(fd,&c,1);
      if(n==0)
         break;
      printf("father:%c\n",c);
      sleep(1);
   } 
  }
  else
  {
     char c;
     while(1)
    {
     int n=read(fd,&c,1);
     if(n==0)
        break;
     printf("child:%c\n",c);
     sleep(1);
    }
  }
 close(fd);
}
