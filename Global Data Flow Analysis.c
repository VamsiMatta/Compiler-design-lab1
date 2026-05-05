#include <stdio.h>

#define MAX 10

// Function to initialize IN and OUT sets
void initializeDataFlow(int nodes, int IN[][MAX], int OUT[][MAX]) {

    for (int i = 0; i < nodes; i++) {
        for (int j = 0; j < MAX; j++) {
            IN[i][j] = 0;   // Initialize IN set to empty
            OUT[i][j] = 0;  // Initialize OUT set to empty
        }
    }
}

// Function to display IN and OUT sets
void displaySets(int nodes, int IN[][MAX], int OUT[][MAX]) {
    printf("\nIN Sets:\n");
    for (int i = 0; i < nodes; i++) {
        printf("Node %d: { ", i);
        for (int j = 0; j < MAX; j++) {
            if (IN[i][j] == 1)
                printf("%d ", j);
        }
        printf("}\n");
    }

    printf("\nOUT Sets:\n");
    for (int i = 0; i < nodes; i++) {
        printf("Node %d: { ", i);
        for (int j = 0; j < MAX; j++) {
            if (OUT[i][j] == 1)
                printf("%d ", j);
        }
        printf("}\n");
    }
}

int main() {
    int nodes;
    int IN[MAX][MAX], OUT[MAX][MAX];

    printf("Enter number of nodes in graph: ");
    scanf("%d", &nodes);

    initializeDataFlow(nodes, IN, OUT);

    displaySets(nodes, IN, OUT);

    return 0;
}
