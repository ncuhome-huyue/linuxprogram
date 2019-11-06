#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
   printf("call:pid=%d,ppid=%d\n",getpid(),getppid());
   system("./1test");
   printf("after calling");

}
