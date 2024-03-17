#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>
int S; sem_t mutex;

void *PUT(void* arg){
    int x;
    sem_wait(&mutex);
    x= S; sleep(2); x+= 50; S= x;
    sem_post(&mutex);
    return NULL; 
}
void *ECDL(void* arg){
    int x;
    sem_wait(&mutex);
    x= S; x+= 70; S= x;
    sem_post(&mutex);
    return NULL; 
}
void run2(void*(*f1)(void* arg), void*(*f2)(void* arg)){
    pthread_t h1, h2;
    pthread_create(&h1, NULL, f1, NULL);
    pthread_create(&h2, NULL, f2, NULL);
    pthread_join(h1, NULL);
    pthread_join(h2, NULL);
}
int main(void){
    S= 7;
    sem_init(&mutex, 0, 1);
    run2(PUT, ECDL);
    printf("S= %d\n", S); 
}