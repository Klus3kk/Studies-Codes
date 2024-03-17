#include <stdio.h>
#include <math.h>
int main() {
    int t[30];
    int n, k;

    printf("Podaj ilosc liczb: ");
    scanf("%d", &n);
    printf("\n----Wybierz opcje----\n\n(1) Ciag od 0 do n - 1\n(2) Ciag od 7 do n + 6\n(3) Ciag 4,8,12,16...\n(4) Ciag 1,2,4,8,16...\n(5) Ciag 2,3,4,...,n+1\n\n");
    scanf("%d", &k);
    if(n > 0 && n < 31) {
        switch (k) {
            case 1:
                for(int i = 0; i < n; i++) {
                    t[i] = i;
                }
                for(int i = 0; i < n; i++) {
                    printf("%d ", t[i]);
                }
                break;
            case 2:
                for(int i = 0; i < n; i++) {
                    t[i] = 7 + i;
                }
                for(int i = 0; i < n; i++) {
                    printf("%d ", t[i]);
                }
                break;
            case 3:
                for(int i = 0; i < n; i++) {
                    t[i] = 4 * (i + 1);
                }
                for(int i = 0; i < n; i++) {
                    printf("%d ", t[i]);
                }
                break;
            case 4:
                for(int i = 0; i < n; i++) {
                    t[i] = (int)pow(2,i);
                }
                for(int i = 0; i < n; i++) {
                    printf("%d ", t[i]);
                }
                break;
            case 5:
                for(int i = 0; i < n; i++) {
                    t[i] = 2 + i;
                }
                for(int i = 0; i < n; i++) {
                    printf("%d ", t[i]);
                }
                break;
            default:
                return 0;
                break;
            } 
    } else {
        printf("\nZla liczba!");
        return 0;
    }
    return 0;
}