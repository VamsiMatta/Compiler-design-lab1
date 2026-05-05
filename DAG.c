#include <stdio.h>
#include <stdlib.h>

// Structure for DAG Node
typedef struct Node {
    char operator;
    struct Node *left;
    struct Node *right;
} Node;

// Function to create a new node
Node* createNode(char op, Node* left, Node* right) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->operator = op;
    newNode->left = left;
    newNode->right = right;
    return newNode;
}

// Function to build DAG for simple expression (a+b)
Node* buildDAG(char expr[]) {
    Node *leftNode, *rightNode, *root;

    // Create leaf nodes for operands
    leftNode = createNode(expr[0], NULL, NULL);
    rightNode = createNode(expr[2], NULL, NULL);

    // Create root node for operator
    root = createNode(expr[1], leftNode, rightNode);

    return root;
}

// Function to display DAG (inorder traversal)
void display(Node* root) {
    if (root != NULL) {
        display(root->left);
        printf("%c ", root->operator);
        display(root->right);
    }
}

int main() {
    char expression[20];
    Node* dagRoot;

    printf("Enter expression (e.g., a+b): ");
    scanf("%s", expression);

    dagRoot = buildDAG(expression);

    printf("\nDAG Inorder Traversal:\n");
    display(dagRoot);

    return 0;
}
