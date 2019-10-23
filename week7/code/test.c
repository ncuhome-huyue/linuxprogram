#include <assert.h>
#include <sys/types.h>
#include <errno.h>
#include <limits.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/stat.h>

void Menu();
void Creatfile(FILE *fp);
void Readfile(FILE *fp);
void Alterfileauthority(FILE *fp);
void Viewfileauthority();

int main()
{
     char choice;
     FILE *fp;
     Menu();
     choice = getchar();
     switch(choice){
      case '0' : 
         printf("退出系统\n");
         exit(0);
        break;
      case '1' : 
         Creatfile(fp);
        break;
      case '2' : 
         Writefile(fp);
        break;
      case '3' : 
         Readfile(fp);
        break;
      case '4' : 
         Alterfileauthority(fp);
        break;
      case '5' : 
         Viewfileauthority();
        break;
      default:
         printf("你的输入有误，退出系统！\n");
         exit(0);
        break; 
     }
     

}
void Menu()
{
      printf("********************************\n");
      printf("0. 退出\n");
      printf("1. 创建新文件\n");
      printf("2. 写文件\n");
      printf("3. 读文件\n");
      printf("4. 修改文件权限\n");
      printf("5. 查看当前文件的权限\n");
      printf("********************************\n");
      printf("Please input your choice(0-5):");
}
void Creatfile(FILE *fp)
{
  char buf[10] ;
  getchar();
  printf("请输入你创建的文件名:");
  fgets(buf, 10, stdin);
  char *find = strchr(buf, '\n');//找出buf中的"\n"
  if(find)
        *find = '\0';   //替换
  if ((fp= fopen(buf, "w+")) == NULL) {
    printf("open error for %m\n", errno);
      exit(1);
  }
  else
  printf("%s file has creat\n",buf);
  if(close(fp)<0){
         perror("close");
       }
       else{
           printf("close xb.txt\n");
       }
  
}
void Writefile(FILE *fp)
{
     char buf[1024];
      getchar();
     if((fp = open("/home/rlk/2/week7/xb.txt",O_CREAT|O_APPEND|O_RDWR,0666)) < 0){
        perror("open");
      }
      else{
         printf("Open file:xb.txt");
      }
      printf("请输入你的内容（不能超过1024个字节）:\n");
      fgets(buf, 10, stdin);
      char *find = strchr(buf, '\n');//找出buf中的"\n"
      if(find)
        *find = '\0';   //替换
      if(write(fp,buf,strlen(buf)) < 0){
           perror("write");
       }
       else{
         printf("成功输入 \n");
      }
      getchar();
      if(close(fp)<0){
         perror("close");
       }
       else{
           printf("close xb.txt\n");
       }

}
void Readfile(FILE *fp)
{
     char *buf;
     int front,rear;
     if((fp = open("/home/rlk/2/week7/xb.txt",O_RDWR,0666)) < 0){
        perror("open");
      }
      else{
         printf("Open file:xb.txt\n");
      }  
      getchar();
      rear = lseek(fp,0,SEEK_END);
      front = lseek(fp,0,SEEK_SET);//设置文件指针位置 
      front = rear - front;
      buf = (char*) malloc(front);
      if(read(fp,buf,front+1)<0){
           perror("read");
       }
       else{
         printf("读取成功 \n");
      }
      printf("文本内容:%s\n",buf);
      getchar();
      if(close(fp)<0){
         perror("close");
       }
       else{
           printf("close xb.txt\n");
       }

}
void Alterfileauthority(FILE *fp)
{
        int n;
        printf("0.读，写，执行 1.读 2.写 3.执行\n"); 
        printf("请选择修改的权限:"); 
        scanf("%d",&n);
        switch(n){
           case 0: chmod("/home/rlk/2/week7/xb.txt",S_IRWXU); break;
           case 1: chmod("/home/rlk/2/week7/xb.txt",S_IRUSR); break;
           case 2: chmod("/home/rlk/2/week7/xb.txt",S_IWUSR); break;
           case 3: chmod("/home/rlk/2/week7/xb.txt",S_IXUSR); break;
           default: printf("你的选择有误请!\n");
        }          
}
void Viewfileauthority()
{
        char *path = "/bin/ls";
        char *argv[4] = {"ls","-l","/home/rlk/2/week7/xb.txt",NULL};
        execv(path,argv);
}

