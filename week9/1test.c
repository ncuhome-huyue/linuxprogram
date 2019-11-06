#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int global1=0;
int global2;

int main()
{
   int i=10;
   static int k=20;
   int pid;
   pid=vfork();
   if(pid<0)
   {
    perror("creat falied");
    }
    else if(pid==0)
    {
            printf("child:pid=%d,ppid=%d,address:i=%p,global1=%p,global2=%p\n",
getpid(),getppid(),&i,&global1,global2);
      global1=999;
      i=12;
      global2=1000;
      k=19;
      exit(0);

    }
    else{
           printf("parent:pid=%d,ppid=%d,address:i=%p,global1=%p,global2=%p\n",
getpid(),getppid(),&i,&global1,global2);
           sleep(10);
           printf("global1=%d,global2=%d,i=%d,k=%d\n",global1,global2,i,k);



      }

}