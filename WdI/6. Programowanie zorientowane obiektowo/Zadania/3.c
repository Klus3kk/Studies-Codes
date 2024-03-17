#include <stdio.h>
int main(void) {
    struct Elem {
        int Id;
        int PLN;
        int Persn;
    };
    typedef struct Elem Student;
    int j;
    Student S[] = { 10, 4200, 7,
                    20, 2000, 3,
                    30, 3000, 2,
                    40, 2200, 2 };
    for (j = 0; !(S[j].PLN / S[j].Persn > 900); j++) {
        printf("%d \n", S[j].Id);
        return 0;
    }
}