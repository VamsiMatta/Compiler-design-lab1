#include <stdio.h>
#include <string.h>

#define MAX 20
#define LEN 20

char grammar[MAX][LEN];
int prodCount;

// Function to check if item already exists
int exists(char items[][LEN], int count, char newItem[]) {
    for (int i = 0; i < count; i++) {
        if (strcmp(items[i], newItem) == 0)
            return 1;
    }
    return 0;
}

// Function to compute closure
void computeClosure(char items[][LEN], int *itemCount) {
    int changed = 1;

    while (changed) {
        changed = 0;

        for (int i = 0; i < *itemCount; i++) {
            char *dotPos = strchr(items[i], '.');

            if (dotPos && *(dotPos + 1) != '\0') {
                char symbol = *(dotPos + 1);

                // If symbol is a non-terminal
                if (symbol >= 'A' && symbol <= 'Z') {

                    for (int j = 0; j < prodCount; j++) {
                        if (grammar[j][0] == symbol) {
                            char newItem[LEN];
                            sprintf(newItem, "%c->.%s", symbol, grammar[j] + 3);

                            if (!exists(items, *itemCount, newItem)) {
                                strcpy(items[*itemCount], newItem);
                                (*itemCount)++;
                                changed = 1;
                            }
                        }
                    }
                }
            }
        }
    }
}

// Function to display closure
void display(char items[][LEN], int count) {
    printf("\nClosure Set:\n");
    for (int i = 0; i < count; i++) {
        printf("%s\n", items[i]);
    }
}

int main() {
    char items[MAX][LEN];
    int itemCount;

    printf("Enter number of productions: ");
    scanf("%d", &prodCount);

    printf("Enter productions (format A->aB):\n");
    for (int i = 0; i < prodCount; i++) {
        scanf("%s", grammar[i]);
    }

    printf("Enter number of initial items: ");
    scanf("%d", &itemCount);

    printf("Enter items (format A->.aB):\n");
    for (int i = 0; i < itemCount; i++) {
        scanf("%s", items[i]);
    }

    computeClosure(items, &itemCount);
    display(items, itemCount);

    return 0;
}
