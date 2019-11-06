#include "my.h"

int main()
{
    int ret;
    char *arg[]={"./test3","123","abc","hello","ncu","edu",NULL};
    printf("call11:pid=%d,ppid=%d\n",getpid(),getppid());
    ret=execvp("test1",arg);
    printf("after calling! ret=%d\n",ret);
    return 0;
}