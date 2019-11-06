#include "my.h"

int main()
{
    int ret;
    printf("call2:pid=%d,ppid=%d\n",getpid(),getppid());
    ret=system("./test3 123 abc hello ncu edu");
    printf("after calling! ret=%d\n",ret);
    return 0;
}
