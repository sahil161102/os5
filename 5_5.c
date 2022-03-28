#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>

int BUFFER_SIZE =100;
int buffer[BUFFER_SIZE];

sem_t cEmpty;
sem_t cFull;
pthread_mutex_t mutex;

/* Threads */
pthread_t tid; /* Thread ID */
//pthread_attr_t attr; /* Thread attributes */

void *producer(void *param);
void *consumer(void *param);
void init();

/* Progress Counter */
int cg;

int main()
{
  init();

  /* Do actual work from this point forward */
  /* Create the producer threads */
 
    pthread_create(&tid,NULL, producer, NULL);
     
 
  /* Create the consumer threads */

    pthread_create(&tid, NULL, consumer, NULL);
 

 printf("Production complete.\n");
  exit(0);
}

void init()
{
  int c2;

  pthread_mutex_init(&mutex, NULL); /* Initialize mutex lock */
 // pthread_attr_init(&attr); /* Initialize pthread attributes to default */
  sem_init(&cFull, 0, 0); /* Initialize full semaphore */
  sem_init(&cEmpty, 0, BUFFER_SIZE); /* Initialize empty semaphore */
  cg = 0; /* Initialize global counter */ 
  for(c2=0;c2<BUFFER_SIZE;c2++) /* Initialize buffer */
  {
    buffer[c2] = 0;
  }
}

void *producer(void *param)
{
  /* Variables */
  int item;

  while(1)
  { 
    sleep(rand());      
    item = (rand()); /* Generates random item */ 

    sem_wait(&cEmpty); /* Lock empty semaphore if not zero */
    pthread_mutex_lock(&mutex);

    if(insert_item(item))
    {
      fprintf(stderr, "Producer error."); 
    }
    else
    {
      printf("Producer produced %d\n", item); 
    }

    pthread_mutex_unlock(&mutex);
    sem_post(&cFull); /* Increment semaphore for # of full */
  }
}

void *consumer(void *param)
{
  int item;

  while(1)
  {
    sleep(rand());
    sem_wait(&cFull); /* Lock empty semaphore if not zero */
    pthread_mutex_lock(&mutex);
    if(remove_item(&item))
    {
      fprintf(stderr, "Consumer error."); 
    }
    else
    {
      printf("Consumer consumed %d\n", item);
    }

    pthread_mutex_unlock(&mutex);
    sem_post(&cEmpty); /* Increments semaphore for # of empty */
  }
}

int insert_item(int item)
{
  if(cg < BUFFER_SIZE) /* Buffer has space */
  {
    buffer[cg] = item;
    cg++;
    return 0;
  }
  else /* Buffer full */
  {
    return -1;
  }
}

int remove_item(int *item)
{
  if(cg > 0) /* Buffer has something in it */
  {
    *item = buffer[(cg-1)];
    cg--;
    return 0;
  }
  else /* Buffer empty */
  {
    return -1;
  }
}
