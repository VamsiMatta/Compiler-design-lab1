#include <stdio.h>
#include <string.h>

#define MAX 50

// Function to display stack and input
void display(char stack[], int top, char input[], int index) {
    printf("Stack: ");
    for (int i = 0; i <= top; i++)
        printf("%c", stack[i]);

    printf("\tInput: %s\n", &input[index]);
}

// Function to check and perform reduction
int reduce(char stack[], int *top) {
    // Rule: id+ → E
    if (*top >= 2) {
        if (stack[*top - 2] == 'i' &&
            stack[*top - 1] == 'd' &&
            stack[*top] == '+') {

            *top -= 2;         // remove id+
            stack[*top] = 'E'; // replace with E
            return 1;
        }
    }
    return 0;
}

int main() {
    char input[MAX];
    char stack[MAX];
    int top = -1;
    int i = 0;

    printf("Enter input string (use i for id, e.g., id+): ");
    scanf("%s", input);

    printf("\nShift-Reduce Process:\n");

    while (1) {
        display(stack, top, input, i);

        // Accept condition
        if (top == 0 && stack[top] == 'E' && input[i] == '\0') {
            printf("String Accepted\n");
            break;
        }

        // Shift operation
        if (input[i] != '\0') {
            stack[++top] = input[i++];
        }

        // Try reduction
        if (reduce(stack, &top)) {
            printf("Reduction performed\n");
        }

        // Stop if no input and no reduction possible
        if (input[i] == '\0' && !reduce(stack, &top)) {
            if (!(top == 0 && stack[top] == 'E')) {
                printf("String Rejected\n");
                break;
            }
        }
    }

    return 0;
}
