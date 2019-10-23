#include <stdio.h>
#include <stdlib.h>
#define SIZE 512
int main(int argc , char *argv[])
{
    char buf[SIZE];        //缓冲区
    if(setvbuf(stdin,buf,_IONBF,SIZE) != 0)  //将标准输入stdin的输入设置为无缓冲
    {
       perror("将标准输入stdin的输入设置为无缓冲失败！\n");
       return 1;
     }
     printf("将标准输入stdin的输入设置为无缓冲成功!\n");
     printf("stdin类型为：");   //打印缓冲区类型
     if(stdin->_flags & _IO_UNBUFFERED) //判断标准输入流对象的缓冲区类型
     {
        printf("无缓冲\n");
     }else if(stdin->_flags & _IO_LINE_BUF)
     {
        printf("行缓冲\n");
     }else{
        printf("全缓冲\n");
     }
     printf("缓冲区大小为 %ld\n",stdin->_IO_buf_end - stdin->_IO_buf_base); //打印缓冲区大小
     printf("文件描述符为:%d\n",fileno(stdin));  //输出文件描述符


}
