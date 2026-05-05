#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Function to check if token is a keyword
int isKeyword(char word[]) {
    char *keywords[] = {"if", "else", "while", "int", "return"};
    int total = 5;

    for (int i = 0; i < total; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

// Function to analyze input string
void analyzeCode(char input[]) {
    int i = 0;
    char token[50];

    while (input[i] != '\0') {

        // Skip spaces
        if (isspace(input[i])) {
            i++;
            continue;
        }

        // Identifier or Keyword
        if (isalpha(input[i]) || input[i] == '_') {
            int j = 0;

            while (isalnum(input[i]) || input[i] == '_') {
                token[j++] = input[i++];
            }
            token[j] = '\0';

            if (isKeyword(token))
                printf("%s -> KEYWORD\n", token);
            else
                printf("%s -> IDENTIFIER\n", token);
        }

        // Number
        else if (isdigit(input[i])) {
            int j = 0;

            while (isdigit(input[i])) {
                token[j++] = input[i++];
            }
            token[j] = '\0';

            printf("%s -> NUMBER\n", token);
        }

        // Operator
        else if (strchr("+-*/=", input[i])) {
            printf("%c -> OPERATOR\n", input[i]);
            i++;
        }

        // Unknown character
        else {
            printf("%c -> UNKNOWN\n", input[i]);
            i++;
        }
    }
}

int main() {
    char code[100];

    printf("Enter code: ");
    fgets(code, sizeof(code), stdin);

    analyzeCode(code);

    return 0;
}
