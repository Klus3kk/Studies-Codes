#include <string.h>
#include <stdio.h>
int main(void) {
    char Expected[100], Provided[100];
    strcpy(Expected, "Warsaw");
    scanf("%s", &Provided);
    if (!strcmp(Expected, Provided))
        printf("OK\n");
    else printf("Wrong!\n");
    return 0;
}