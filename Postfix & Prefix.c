#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 50

// Stack implementation
char stack[MAX];
int top = -1;

// Push operation
void push(char ch) {
    stack[++top] = ch;
}

// Pop operation
char pop() {
    return stack[top--];
}

// Peek operation
char peek() {
    return stack[top];
}

// Function to return precedence
int getPriority(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// Convert infix to postfix
void convertToPostfix(char infix[], char postfix[]) {
    int i = 0, k = 0;

    while (infix[i] != '\0') {
        char ch = infix[i];

        // Operand
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // Operator
        else {
            while (top != -1 && getPriority(peek()) >= getPriority(ch)) {
                postfix[k++] = pop();
            }
            push(ch);
        }
        i++;
    }

    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }

    postfix[k] = '\0';
}

// Main function
int main() {
    char infix[MAX], postfix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    convertToPostfix(infix, postfix);

    printf("Postfix Expression: %s\n", postfix);

    return 0;
}
