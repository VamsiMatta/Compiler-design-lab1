#include <stdio.h>
#include <string.h>

#define MAX 10
#define LEN 20

char productions[MAX][LEN];
int prodCount;

// Function to compute LEADING
void findLeading(char nonTerminal) {
    printf("\nLEADING(%c) = { ", nonTerminal);

    for (int i = 0; i < prodCount; i++) {
        if (productions[i][0] == nonTerminal) {
            char first = productions[i][3]; // A->...

            printf("%c ", first);
        }
    }

    printf("}\n");
}

// Function to compute TRAILING
void findTrailing(char nonTerminal) {
    printf("TRAILING(%c) = { ", nonTerminal);

    for (int i = 0; i < prodCount; i++) {
        if (productions[i][0] == nonTerminal) {
            int len = strlen(productions[i]);
            char last = productions[i][len - 1];

            printf("%c ", last);
        }
    }

    printf("}\n");
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &prodCount);

    printf("Enter productions (format A->aB):\n");
    for (int i = 0; i < prodCount; i++) {
        scanf("%s", productions[i]);
    }

    // Find LEADING and TRAILING for each non-terminal
    for (int i = 0; i < prodCount; i++) {
        char nt = productions[i][0];
        findLeading(nt);
        findTrailing(nt);
    }

    return 0;
}
