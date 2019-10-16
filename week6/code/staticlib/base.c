#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>
#include <time.h>

void show(int* a,int n)
{
    int i;
     for(i=0;i<n;i++)
         printf("%4d : %4d\n",i,a[i]);

}

void init(int *a,int n)
{
    srand((int)time(0));
    for(int i=0;i<n;i++)
      a[i]=(int)(100*(rand()/(RAND_MAX+1.0)));
}
