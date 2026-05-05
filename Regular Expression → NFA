#include <stdio.h>
#include <string.h>

#define MAX 10

// Structure to represent NFA
typedef struct {
    int transition[MAX][MAX];  // adjacency matrix
    int startState;
    int finalState;
    int totalStates;
} NFA;

// Function to initialize NFA
void setupNFA(NFA *nfa) {
    nfa->startState = 0;
    nfa->finalState = 1;
    nfa->totalStates = 2;

    // Initialize transitions to 0
    for (int i = 0; i < MAX; i++) {
        for (int j = 0; j < MAX; j++) {
            nfa->transition[i][j] = 0;
        }
    }
}

// Function to create simple NFA for single character regex
void buildNFA(NFA *nfa, char symbol) {
    // Add transition from start to final state
    nfa->transition[nfa->startState][nfa->finalState] = symbol;
}

// Function to display NFA
void displayNFA(NFA *nfa) {
    printf("\nNFA Transition Table:\n");

    for (int i = 0; i < nfa->totalStates; i++) {
        for (int j = 0; j < nfa->totalStates; j++) {
            if (nfa->transition[i][j] != 0) {
                printf("State %d --%c--> State %d\n",
                       i, nfa->transition[i][j], j);
            }
        }
    }

    printf("Start State: %d\n", nfa->startState);
    printf("Final State: %d\n", nfa->finalState);
}

int main() {
    NFA myNFA;
    char regex;

    printf("Enter a single character regex: ");
    scanf(" %c", &regex);

    setupNFA(&myNFA);
    buildNFA(&myNFA, regex);

    displayNFA(&myNFA);

    return 0;
}
