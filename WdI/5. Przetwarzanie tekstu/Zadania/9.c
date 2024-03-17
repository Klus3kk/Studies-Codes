#include <string.h>
#include <stdio.h>
int main() {
    char Expected[] = "Warsaw";
    char Provided[100];
    scanf("%s", Provided);
    if (!strcmp(Expected, Provided))
        printf("OK\n");
    else printf("Wrong!\n");
    return 0;
}