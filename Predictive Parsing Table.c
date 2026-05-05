#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char productions[MAX][10];
char nonTerminals[MAX];
char terminals[MAX];
char table[10][10][10]; // parsing table
int prodCount, ntCount = 0, tCount = 0;

// Function to check and add non-terminal
void addNonTerminal(char ch) {
    for (int i = 0; i < ntCount; i++) {
        if (nonTerminals[i] == ch)
            return;
    }
    nonTerminals[ntCount++] = ch;
}

// Function to check and add terminal
void addTerminal(char ch) {
    if (!isupper(ch) && ch != '-' && ch != '>') {
        for (int i = 0; i < tCount; i++) {
            if (terminals[i] == ch)
                return;
        }
        terminals[tCount++] = ch;
    }
}

// Simple FIRST (only first character logic)
char getFirst(char *prod) {
    return prod[3]; // A->a
}

// Get index of non-terminal
int getNTIndex(char ch) {
    for (int i = 0; i < ntCount; i++) {
        if (nonTerminals[i] == ch)
            return i;
    }
    return -1;
}

// Get index of terminal
int getTIndex(char ch) {
    for (int i = 0; i < tCount; i++) {
        if (terminals[i] == ch)
            return i;
    }
    return -1;
}

// Construct predictive parsing table
void buildTable() {
    for (int i = 0; i < prodCount; i++) {
        char A = productions[i][0];
        char first = getFirst(productions[i]);

        int row = getNTIndex(A);
        int col = getTIndex(first);

        if (row != -1 && col != -1) {
            strcpy(table[row][col], productions[i]);
        }
    }
}

// Display table
void displayTable() {
    printf("\nPredictive Parsing Table:\n\n");

    printf("   ");
    for (int i = 0; i < tCount; i++) {
        printf("  %c  ", terminals[i]);
    }
    printf("\n");

    for (int i = 0; i < ntCount; i++) {
        printf("%c ", nonTerminals[i]);

        for (int j = 0; j < tCount; j++) {
            if (strlen(table[i][j]) > 0)
                printf(" %s ", table[i][j]);
            else
                printf("  -  ");
        }
        printf("\n");
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &prodCount);

    printf("Enter productions (format A->aB):\n");
    for (int i = 0; i < prodCount; i++) {
        scanf("%s", productions[i]);

        addNonTerminal(productions[i][0]);

        for (int j = 3; productions[i][j] != '\0'; j++) {
            addTerminal(productions[i][j]);
        }
    }

    buildTable();
    displayTable();

    return 0;
}
