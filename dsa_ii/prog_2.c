#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char items[MAX];
    int top;
} OpStack;

void setupStack(OpStack *s) {
    s->top = -1;
}

bool stackEmpty(OpStack *s) {
    return s->top == -1;
}

void pushOp(OpStack *s, char op) {
    if (s->top < MAX - 1) {
        s->items[++s->top] = op;
    }
}

char popOp(OpStack *s) {
    if (!stackEmpty(s)) {
        return s->items[s->top--];
    }
    return '\0';
}

char checkTop(OpStack *s) {
    if (!stackEmpty(s)) {
        return s->items[s->top];
    }
    return '\0';
}

int checkPriority(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

void infixToPost(char *input, char *output) {
    OpStack stack;
    setupStack(&stack);
    int pos = 0;
    
    for (int i = 0; input[i] != '\0'; i++) {
        char current = input[i];
        
        if (isspace(current)) continue;
        
        if (isdigit(current) || current == '.') {
            while (isdigit(input[i]) || input[i] == '.' || input[i] == ' ') {
                if (!isspace(input[i])) {
                    output[pos++] = input[i];
                }
                i++;
            }
            i--;
            output[pos++] = ' ';
        }
        else if (current == '(') {
            pushOp(&stack, current);
        }
        else if (current == ')') {
            while (!stackEmpty(&stack) && checkTop(&stack) != '(') {
                output[pos++] = popOp(&stack);
                output[pos++] = ' ';
            }
            popOp(&stack);
        }
        else {
            while (!stackEmpty(&stack) && checkPriority(checkTop(&stack)) >= checkPriority(current)) {
                output[pos++] = popOp(&stack);
                output[pos++] = ' ';
            }
            pushOp(&stack, current);
        }
    }
    
    while (!stackEmpty(&stack)) {
        output[pos++] = popOp(&stack);
        output[pos++] = ' ';
    }
    output[pos] = '\0';
}

double calculatePost(char *post) {
    double numStack[MAX];
    int top = -1;
    char *part = strtok(post, " ");
    
    while (part != NULL) {
        if (isdigit(part[0])) {
            numStack[++top] = atof(part);
        }
        else {
            double num2 = numStack[top--];
            double num1 = numStack[top--];
            
            switch (part[0]) {
                case '+': numStack[++top] = num1 + num2; break;
                case '-': numStack[++top] = num1 - num2; break;
                case '*': numStack[++top] = num1 * num2; break;
                case '/': 
                    if (num2 == 0) {
                        printf("Math error\n");
                        exit(1);
                    }
                    numStack[++top] = num1 / num2; 
                    break;
                default:
                    printf("Invalid operator\n");
                    exit(1);
            }
        }
        part = strtok(NULL, " ");
    }
    return numStack[top];
}

int main() {
    char input[MAX];
    char output[MAX * 2];
    
    printf("Enter expression: ");
    fgets(input, MAX, stdin);
    input[strcspn(input, "\n")] = '\0';
    
    infixToPost(input, output);
    printf("Postfix: %s\n", output);
    
    double result = calculatePost(strdup(output));
    printf("Result: %.2f\n", result);
    
    return 0;
}