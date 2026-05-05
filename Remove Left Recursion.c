#include <stdio.h>
#include <string.h>

#define MAX 10
#define LEN 20

// Function to remove immediate left recursion
void removeLeftRecursion(char nonTerminal, char productions[MAX][LEN], int count) {
    char alpha[MAX][LEN]; // left recursive part
    char beta[MAX][LEN];  // non-left recursive part
    int aCount = 0, bCount = 0;

    // Separate alpha and beta
    for (int i = 0; i < count; i++) {
        if (productions[i][0] == nonTerminal) {
            // remove A from beginning
            strcpy(alpha[aCount], productions[i] + 1);
            aCount++;
        } else {
            strcpy(beta[bCount], productions[i]);
            bCount++;
        }
    }

    // If left recursion exists
    if (aCount > 0) {
        printf("\nAfter removing left recursion:\n");

        // A → βA'
        printf("%c -> ", nonTerminal);
        for (int i = 0; i < bCount; i++) {
            printf("%s%c' ", beta[i], nonTerminal);
            if (i != bCount - 1)
                printf("| ");
        }

        // A' → αA' | ε
        printf("\n%c' -> ", nonTerminal);
        for (int i = 0; i < aCount; i++) {
            printf("%s%c' ", alpha[i], nonTerminal);
            if (i != aCount - 1)
                printf("| ");
        }
        printf("| ε\n");
    } else {
        printf("\nNo Left Recursion Found.\n");
    }
}

int main() {
    int n;
    char nonTerminal;
    char productions[MAX][LEN];

    printf("Enter Non-Terminal (e.g., A): ");
    scanf(" %c", &nonTerminal);

    printf("Enter number of productions: ");
    scanf("%d", &n);

    printf("Enter productions (e.g., Aa or b):\n");
    for (int i = 0; i < n; i++) {
        scanf("%s", productions[i]);
    }

    removeLeftRecursion(nonTerminal, productions, n);

    return 0;
}
