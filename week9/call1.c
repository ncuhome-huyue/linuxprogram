#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
   char *argv[2];
   argv[0]="./test";
   argv[1]=NULL;
   printf("call:pid=%d,ppid=%d\n",getpid(),getppid());
   execv("./test",argv);
   printf("after calling");

}
