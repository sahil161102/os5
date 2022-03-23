#include <stdio.h>
#include <stdlib.h>
#include<pthread.h>
#include <unistd.h>

int a =5;

void *decrement_func(){
sleep(1);
a--;
printf("a = %d\n",a);
}

void *increment_func(){
sleep(1);

a++;
printf("a = %d\n",a);
}


int main(){
int result=1;
pthread_t t1;
pthread_t t2;

pthread_create(&t1,NULL,increment_func,NULL);

pthread_create(&t2,NULL,decrement_func,NULL);

pthread_join(t1,NULL);
pthread_join(t2,NULL);
exit(0);
}

