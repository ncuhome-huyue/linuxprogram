#include "my.h"
int tickets=100;
sem_t space,product;
pthread_mutex_t mutex;
void *p1(void *arg)
{
  while(1)
  {
    sem_wait(&empty);
    if(tickets>0)
    {
	//usleep(1000);
	printf("worker0 read ticket:%d\n",tickets--);
	sem_post(&full);
    } 
    else
    {
	sem_post(&full);
	break;
    }
    pthread_yield();
  }
  return NULL;
}
void *c1(void *arg)
{
  while(1)
  {
    sem_wait(&full);
    if(tickets>0)
    {
	//usleep(1000);
	printf("worker1 read ticket:%d\n",tickets--);
	sem_post(&empty);
    } 
    else
    {
	sem_post(&empty);
	break;
    }
  }
  return NULL;
}
int main(){
  pthread_t tid[2];
  int i,ret;
  void *(*pt[2])();
  pt[0]=p1;
  pt[1]=c1;
  ret=sem_init(&space,0,5);
  ret=sem_init(&product,0,0);
  for(i=0;i<2;i++)
  {
    ret=pthread_create(&tid[i],NULL,pt[i],NULL);
    if(ret!=0)
    {
	perror("create thread!\n");
	exit(1);
    }
  }
  for(i=0;i<2;i++)
  {
    pthread_join(tid[i],NULL);
  }
  return 0;

}
