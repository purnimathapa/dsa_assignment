#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

char stack[SIZE];
int top = -1;
void push(char c) {
    if (top < SIZE - 1) {
        stack[++top] = c;
    }
}

char pop() {
    if (top >= 0) {
        return stack[top--];
    }
    return '\0';
}

char peek() {
    if (top >= 0) {
        return stack[top];
    }
    return '\0';
}

int isMatchingPair(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

int isBalanced(char *expr) {
    top = -1; 

    for (int i = 0; expr[i] != '\0'; i++) {
        char c = expr[i];

        if (c == '(' || c == '[' || c == '{') {
            push(c);
        } else if (c == ')' || c == ']' || c == '}') {
            if (top == -1 || !isMatchingPair(pop(), c)) {
                return 0; 
            }
        }
    }

    return (top == -1); 
}

int main() {
    char *expressions[] = {
        "a+ (b− c) * (d",
        "m+ [a− b * (c+ d * {m)]",
        "a+ (b− c)"
    };

    for (int i = 0; i < 3; i++) {
        printf("Expression: %s\n", expressions[i]);
        if (isBalanced(expressions[i])) {
            printf("=> Balanced\n\n");
        } else {
            printf("=> Not Balanced\n\n");
        }
    }

    return 0;
}
// Written and tested by Purnima Thapa
