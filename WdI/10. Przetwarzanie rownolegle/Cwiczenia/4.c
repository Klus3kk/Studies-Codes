#include <pthread.h>
#include <stdio.h>

int S;

void *PUT(void* arg) {
    int x;
    x = S;
    x += 50;
    S = x;
    // return NULL;
}

void *ECDL(void* arg) {
    int x;
    x = S;
    x += 70;
    S = x;
    // return NULL;
}

int main(void) {
    pthread_t PUT_h, ECDL_h;
    S = 7;
    pthread_create(&PUT_h, NULL, PUT, NULL);
    pthread_create(&ECDL_h, NULL, ECDL, NULL);
    pthread_join(PUT_h, NULL);
    pthread_join(ECDL_h, NULL);
    printf("S = %d\n", S);
}