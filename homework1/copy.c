#include<stdio.h>
#include<assert.h>
#include<string.h>
#include<fcntl.h>
#include<sys/types.h>
int main(int argc,char *argv[])
{
   int fd1=open(argv[1],O_RDWR|O_CREAT,0777);
   pid_t pid=fork();
   assert(pid!=-1);
   if(pid==0)
 {
    char buff[128]="hello,world";
    write(fd1,buff,strlen(buff));
    lseek(fd1,0,SEEK_SET);
 }
else
{  
   sleep(2);
   char buff[128] = {0};
   int fd2=open(argv[2],O_RDWR|O_CREAT,0777);
   while(1)
{
  int n=read(fd1,buff,3);
  if(n==0)
    break; 
   write(fd2,buff,n);
}

  // buff[11] ='\0';

 //  write(fd2,buff,strlen(buff));
   close(fd2);
}
    close(fd1);
}
