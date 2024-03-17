#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
int S;
void *PUT(void* arg){
    int x;
    x= S; sleep(2); x+= 50; S= x;
    return NULL; 
}
void *ECDL(void* arg){
    int x;
    x= S; x+= 70; S= x;
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
    run2(ECDL, PUT);
    printf("S= %d\n", S); 
}