#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>
#include <unistd.h>
#include <semaphore.h>

int a =5;
sem_t s;

void *decrement_func(){
sem_wait(&s);
sleep(1);
a--;
printf("a = %d\n",a);
sem_post(&s);
}

void *increment_func(){
sem_wait(&s);
sleep(1);
a++;
printf("a = %d\n",a);
sem_post(&s);
}

int main(){
int result=1;
pthread_t t1;
pthread_t t2;

sem_init(&s,0,1);
pthread_create(&t1,NULL,increment_func,NULL);
pthread_create(&t2,NULL,decrement_func,NULL);

pthread_join(t1,NULL);
pthread_join(t2,NULL);
exit(0);
}

