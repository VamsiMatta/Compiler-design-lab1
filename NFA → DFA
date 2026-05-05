#include <stdio.h>

#define MAX 10

// Structure for NFA
typedef struct {
    int transitions[MAX][2][MAX]; // [state][symbol][next states]
    int count[MAX][2];            // number of transitions
    int states;
} NFA;

// Structure for DFA
typedef struct {
    int states[MAX][MAX];   // set of NFA states
    int size[MAX];          // size of each set
    int transitions[MAX][2]; // DFA transitions
    int totalStates;
} DFA;

// Function to check if a state set already exists
int isExisting(DFA *dfa, int newSet[], int newSize) {
    for (int i = 0; i < dfa->totalStates; i++) {
        if (dfa->size[i] == newSize) {
            int match = 1;
            for (int j = 0; j < newSize; j++) {
                if (dfa->states[i][j] != newSet[j]) {
                    match = 0;
                    break;
                }
            }
            if (match) return i;
        }
    }
    return -1;
}

// Function to perform NFA → DFA conversion
void convert(NFA *nfa, DFA *dfa) {
    int queue[MAX], front = 0, rear = 0;

    // Initial DFA state = {0}
    dfa->states[0][0] = 0;
    dfa->size[0] = 1;
    dfa->totalStates = 1;

    queue[rear++] = 0;

    while (front < rear) {
        int current = queue[front++];

        for (int sym = 0; sym < 2; sym++) {
            int newSet[MAX], newSize = 0;

            // For each NFA state in current DFA state
            for (int i = 0; i < dfa->size[current]; i++) {
                int state = dfa->states[current][i];

                for (int j = 0; j < nfa->count[state][sym]; j++) {
                    int next = nfa->transitions[state][sym][j];

                    // Avoid duplicates
                    int found = 0;
                    for (int k = 0; k < newSize; k++) {
                        if (newSet[k] == next) {
                            found = 1;
                            break;
                        }
                    }
                    if (!found)
                        newSet[newSize++] = next;
                }
            }

            if (newSize == 0) {
                dfa->transitions[current][sym] = -1;
            } else {
                int index = isExisting(dfa, newSet, newSize);

                if (index == -1) {
                    index = dfa->totalStates;

                    for (int i = 0; i < newSize; i++)
                        dfa->states[index][i] = newSet[i];

                    dfa->size[index] = newSize;
                    dfa->totalStates++;

                    queue[rear++] = index;
                }

                dfa->transitions[current][sym] = index;
            }
        }
    }
}

// Function to display DFA
void displayDFA(DFA *dfa) {
    printf("\nDFA Transition Table:\n");

    for (int i = 0; i < dfa->totalStates; i++) {
        printf("State %d { ", i);
        for (int j = 0; j < dfa->size[i]; j++) {
            printf("%d ", dfa->states[i][j]);
        }
        printf("}\n");

        printf("  on 'a' -> %d\n", dfa->transitions[i][0]);
        printf("  on 'b' -> %d\n", dfa->transitions[i][1]);
    }
}

int main() {
    NFA nfa = {0};
    DFA dfa = {0};

    // Example NFA (you can change this)
    nfa.states = 2;

    // State 0 --a--> 0,1
    nfa.transitions[0][0][0] = 0;
    nfa.transitions[0][0][1] = 1;
    nfa.count[0][0] = 2;

    // State 0 --b--> 0
    nfa.transitions[0][1][0] = 0;
    nfa.count[0][1] = 1;

    // State 1 --b--> 1
    nfa.transitions[1][1][0] = 1;
    nfa.count[1][1] = 1;

    convert(&nfa, &dfa);
    displayDFA(&dfa);

    return 0;
}
