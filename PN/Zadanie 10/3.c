#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void read_array(double A[100], int n) {
    for(int i = 0; i < n; i++) {
        printf("Wprowadz liczbe A[%d]: ", i);
        scanf("%lf", &A[i]);
    }
}

void add(double A[100], int n) {
    double x;
    printf("Podaj x: ");
    scanf("%lf", &x);
    for(int i = 0; i < n; i++) {
        A[i] += x;
    }
}

void substract(double A[100], int n) {
    double x;
    printf("Podaj x: ");
    scanf("%lf", &x);
    for(int i = 0; i < n; i++) {
        A[i] -= x;
    }
}

void write_array(double A[100], int n) {
    for(int i = 0; i < n; i++) {
        printf("A[%d] = %lf\n", i, A[i]);
    }
}

int main() {
    char option;
    int n;
    bool initialized = false;
    printf("Podaj n: ");
    scanf("%d", &n);
    while(n < 1 || n > 100) {
        printf("Podaj n: ");
        scanf("%d", &n);
    }
    double A[100];
    while(true) {
        printf("Podaj opcje: N - wczytaj tablice, D - dodaj liczbe do tablicy, O - odejmij liczbe od tablicy, W - wypisz tablice, K - koniec: ");
        fflush(stdin);
        scanf("%c", &option);
        switch(option) {
            case 'N':
                read_array(A,n);
                initialized = true;
                break;
            case 'D':
                if(!initialized) {
                    printf("Tablica nie zostala zainicjalizowana.\n");
                    break;
                } else {
                    add(A,n);
                }
                break;
            case 'O':
                if(!initialized) {
                    printf("Tablica nie zostala zainicjalizowana.\n");
                    break;
                } else {
                    substract(A,n);
                }
                break;
            case 'W':
                if(!initialized) {
                    printf("Tablica nie zostala zainicjalizowana.\n");
                    break;
                } else {
                    write_array(A,n);
                }
                break;
            case 'K':
                return 0;
            default:
                printf("Nieznana opcja\n");
        }
    }
}