#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// the hardest exercise yet
char* gsub(const char* r, const char* s, char* t) {
    char buffer[1024] = { 0 };
    char* p = t;

    while((p = strstr(p, r)) != NULL) {
        strncpy(buffer, t, p - t);
        buffer[p - t] = '\0';
        strcat(buffer, s);
        strcat(buffer, p + strlen(r));
        strcpy(t, buffer);
        p++;
    }

    return t;
}

char* gensub(const char* r, const char* s, int h, char* t) {
    char buffer[1024] = { 0 };
    char* p = t;
    int count = 0;

    while((p = strstr(p, r)) != NULL) {
        count++;
        if(count == h) {
            strncpy(buffer, t, p - t);
            buffer[p - t] = '\0';
            strcat(buffer, s);
            strcat(buffer, p + strlen(r));
            strcpy(t, buffer);
            return t;
        }
        p++;
    }

    return t;
}


int index(const char* s, const char* t) {
    char* p = strstr(s, t);
    if(p) return p - s;
    return -1;
}


int split(const char* s, char*** a, const char* fs) {
    int count = 0;
    char* tmp;
    char* token;
    char* str = strdup(s);

    token = strtok(str, fs);
    while(token != NULL) {
        *a = realloc(*a, sizeof(char*) * ++count);
        (*a)[count - 1] = strdup(token);
        token = strtok(NULL, fs);
    }

    *a = realloc(*a, sizeof(char*) * ++count);
    (*a)[count - 1] = 0;

    free(str);
    return count - 1;
}


char* sub(const char* r, const char* s, char* t) {
    char buffer[1024] = { 0 };
    char* p = strstr(t, r);

    if(p) {
        strncpy(buffer, t, p - t);
        buffer[p - t] = '\0';
        strcat(buffer, s);
        strcat(buffer, p + strlen(r));
        strcpy(t, buffer);
    }

    return t;
}



int main() {
    char str[100];
    printf("Enter a string: ");
    fgets(str, 100, stdin);
    str[strcspn(str, "\n")] = 0;  

    int choice;
    printf("Choose an operation:\n");
    printf("1. gsub\n");
    printf("2. gensub\n");
    printf("3. index\n");
    printf("4. split\n");
    printf("5. sub\n");
    printf("Your choice: ");
    scanf("%d", &choice);

    char param1[100], param2[100];
    int param3;

    switch (choice) {
        case 1:
            printf("Enter first parameter: ");
            scanf("%s", param1);
            printf("Enter second parameter: ");
            scanf("%s", param2);
            printf("Result of gsub: %s\n", gsub(param1, param2, str));
            break;
        case 2:
            printf("Enter first parameter: ");
            scanf("%s", param1);
            printf("Enter second parameter: ");
            scanf("%s", param2);
            printf("Enter third parameter: ");
            scanf("%d", &param3);
            printf("Result of gensub: %s\n", gensub(param1, param2, param3, str));
            break;
        case 3:
            printf("Enter parameter: ");
            scanf("%s", param1);
            printf("Result of index: %d\n", index(str, param1));
            break;
        case 4:
            printf("Enter parameter: ");
            scanf("%s", param1);
            char* arr[100];
            int count = split(str, &arr, param1);
            printf("Result of split: ");
            for (int i = 0; i < count; i++) {
                printf("%s ", arr[i]);
            }
            printf("\n");
            break;
        case 5:
            printf("Enter first parameter: ");
            scanf("%s", param1);
            printf("Enter second parameter: ");
            scanf("%s", param2);
            printf("Result of sub: %s\n", sub(param1, param2, str));
            break;
        default:
            printf("Invalid choice.\n");
    }

    return 0;
}