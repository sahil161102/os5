#include <stdio.h>
#include<pthread.h>
int a =5;

void *increment_func( ){
a++;
printf("a = %d\n",a);
}
void *decrement_func(){
a--;
printf("a = %d\n",a);
}

int main(){
int result=1;
pthread_t t1;
pthread_t t2;

result = pthread_create(&t1,NULL,increment_func,NULL);
if(result)
printf("thread1Not created");
result = pthread_create(&t2,NULL,decrement_func,NULL);
if(result)
printf("thread2Not created");
}

