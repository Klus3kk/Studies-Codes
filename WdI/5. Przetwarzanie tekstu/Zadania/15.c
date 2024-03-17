#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#define maxSize 100
int main(void){
    regex_t regRep;
    char *regEx= "ne"; /* <‐‐ Regular expression */
    char *txtPtr;
    size_t lineSize= maxSize-1;  
    int er;
    txtPtr= (char *)malloc(maxSize);
    er= regcomp(&regRep, regEx, REG_EXTENDED | REG_NEWLINE);
    if (er != 0){
       printf("Error in regular expression\n");
       return 0; }
    while (getline(&txtPtr, &lineSize, stdin) > 0){
       er= regexec(&regRep, txtPtr, 0, NULL, 0);
       if (er == 0){
          printf("%s", txtPtr); /* <‐‐ Action */
           }
       }
    regfree(&regRep);
    return 0;
} 