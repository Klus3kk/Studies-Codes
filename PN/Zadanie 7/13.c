#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int num) {
    if (top >= MAX_SIZE - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack[++top] = num;
}

int pop() {
    if (top == -1) {
        printf("Stack underflow\n");
        return -1;
    }
    return stack[top--];
}

int evaluateRPN(char* expression) {
    char* token = strtok(expression, ",");
    while (token != NULL) {
        if (strcmp(token, "+") == 0) {
            int num1 = pop();
            int num2 = pop();
            push(num2 + num1);
        } else if (strcmp(token, "-") == 0) {
            int num1 = pop();
            int num2 = pop();
            push(num2 - num1);
        } else if (strcmp(token, "*") == 0) {
            int num1 = pop();
            int num2 = pop();
            push(num2 * num1);
        } else if (strcmp(token, "/") == 0) {
            int num1 = pop();
            int num2 = pop();
            if (num1 == 0) {
                printf("Division by zero\n");
                return -1;
            }
            push(num2 / num1);
        } else if (strcmp(token, "^") == 0) {
            int num1 = pop();
            int num2 = pop();
            push(pow(num2, num1));
        } else {
            push(atoi(token));
        }
        token = strtok(NULL, ",");
    }
    return pop();
}

int main() {
    char expression[] = "3,2,-,1,+";
    printf("Result: %d\n", evaluateRPN(expression));
    return 0;
}