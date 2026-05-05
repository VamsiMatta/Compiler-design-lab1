#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

char productions[MAX][10];
char firstSet[26][10];
char followSet[26][10];
int prodCount;

// Utility to add symbol to set (avoid duplicates)
void addToSet(char set[], char symbol) {
    for (int i = 0; set[i] != '\0'; i++) {
        if (set[i] == symbol)
            return;
    }
    int len = strlen(set);
    set[len] = symbol;
    set[len + 1] = '\0';
}

// Function to compute FIRST
void computeFirst(char symbol) {
    if (!isupper(symbol)) {
        addToSet(firstSet[symbol - 'A'], symbol);
        return;
    }

    for (int i = 0; i < prodCount; i++) {
        if (productions[i][0] == symbol) {
            char next = productions[i][3]; // A->X

            if (!isupper(next)) {
                addToSet(firstSet[symbol - 'A'], next);
            } else {
                computeFirst(next);
                for (int j = 0; firstSet[next - 'A'][j] != '\0'; j++) {
                    addToSet(firstSet[symbol - 'A'], firstSet[next - 'A'][j]);
                }
            }
        }
    }
}

// Function to compute FOLLOW
void computeFollow(char symbol) {
    if (symbol == productions[0][0]) {
        addToSet(followSet[symbol - 'A'], '$');
    }

    for (int i = 0; i < prodCount; i++) {
        for (int j = 3; productions[i][j] != '\0'; j++) {
            if (productions[i][j] == symbol) {

                // If not last symbol
                if (productions[i][j + 1] != '\0') {
                    char next = productions[i][j + 1];

                    if (!isupper(next)) {
                        addToSet(followSet[symbol - 'A'], next);
                    } else {
                        for (int k = 0; firstSet[next - 'A'][k] != '\0'; k++) {
                            addToSet(followSet[symbol - 'A'], firstSet[next - 'A'][k]);
                        }
                    }
                }
                // If last symbol
                else {
                    char lhs = productions[i][0];
                    if (lhs != symbol) {
                        computeFollow(lhs);
                        for (int k = 0; followSet[lhs - 'A'][k] != '\0'; k++) {
                            addToSet(followSet[symbol - 'A'], followSet[lhs - 'A'][k]);
                        }
                    }
                }
            }
        }
    }
}

// Display results
void displaySets() {
    printf("\nFIRST Sets:\n");
    for (int i = 0; i < 26; i++) {
        if (firstSet[i][0] != '\0') {
            printf("%c : { %s }\n", i + 'A', firstSet[i]);
        }
    }

    printf("\nFOLLOW Sets:\n");
    for (int i = 0; i < 26; i++) {
        if (followSet[i][0] != '\0') {
            printf("%c : { %s }\n", i + 'A', followSet[i]);
        }
    }
}

int main() {
    printf("Enter number of productions: ");
    scanf("%d", &prodCount);

    printf("Enter productions (format A->aB):\n");
    for (int i = 0; i < prodCount; i++) {
        scanf("%s", productions[i]);
    }

    // Initialize sets
    for (int i = 0; i < 26; i++) {
        firstSet[i][0] = '\0';
        followSet[i][0] = '\0';
    }

    // Compute FIRST
    for (int i = 0; i < prodCount; i++) {
        computeFirst(productions[i][0]);
    }

    // Compute FOLLOW
    for (int i = 0; i < prodCount; i++) {
        computeFollow(productions[i][0]);
    }

    displaySets();

    return 0;
}
