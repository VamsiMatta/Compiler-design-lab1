#include <stdio.h>
#include <string.h>

#define MAX 50

// Structure for Quadruple
typedef struct {
    char op;
    char arg1[10];
    char arg2[10];
    char result[10];
} Quad;

// Function to generate quadruples
void generateQuadruples(char expr[]) {
    char tokens[MAX][10];
    int count = 0;
    int tempNum = 1;

    // Split expression into tokens (character-wise)
    for (int i = 0; expr[i] != '\0'; i++) {
        tokens[count][0] = expr[i];
        tokens[count][1] = '\0';
        count++;
    }

    Quad quadList[MAX];
    int qIndex = 0;

    // Generate quadruples
    while (count > 1) {
        int opPos = 1; // operator position (simple assumption)

        sprintf(quadList[qIndex].arg1, "%s", tokens[opPos - 1]);
        sprintf(quadList[qIndex].arg2, "%s", tokens[opPos + 1]);
        quadList[qIndex].op = tokens[opPos][0];

        sprintf(quadList[qIndex].result, "T%d", tempNum);

        // Replace first three tokens with result
        strcpy(tokens[0], quadList[qIndex].result);

        for (int i = 3; i < count; i++) {
            strcpy(tokens[i - 2], tokens[i]);
        }

        count -= 2;
        tempNum++;
        qIndex++;
    }

    // Display quadruples
    printf("\nQuadruple Representation:\n");
    printf("Op\tArg1\tArg2\tResult\n");

    for (int i = 0; i < qIndex; i++) {
        printf("%c\t%s\t%s\t%s\n",
               quadList[i].op,
               quadList[i].arg1,
               quadList[i].arg2,
               quadList[i].result);
    }
}

int main() {
    char expression[MAX];

    printf("Enter expression (e.g., a+b*c): ");
    scanf("%s", expression);

    generateQuadruples(expression);

    return 0;
}
