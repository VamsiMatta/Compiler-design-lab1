#include <stdio.h>
#include <string.h>

// Function to generate simple assembly-like code
void generateCode(char expr[]) {
    char op1, op2, operator;

    // Extract operands and operator (assuming a+b format)
    op1 = expr[0];
    operator = expr[1];
    op2 = expr[2];

    printf("\nGenerated Code:\n");

    // Move first operand into register
    printf("MOV R1, %c\n", op1);

    // Perform operation based on operator
    switch (operator) {
        case '+':
            printf("ADD R1, %c\n", op2);
            break;
        case '-':
            printf("SUB R1, %c\n", op2);
            break;
        case '*':
            printf("MUL R1, %c\n", op2);
            break;
        case '/':
            printf("DIV R1, %c\n", op2);
            break;
        default:
            printf("Invalid Operator\n");
    }
}

int main() {
    char expression[20];

    printf("Enter expression (e.g., a+b): ");
    scanf("%s", expression);

    generateCode(expression);

    return 0;
}
