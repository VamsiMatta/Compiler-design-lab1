#include <stdio.h>

#define MAX 50

// Stack structure
typedef struct {
    int data[MAX];
    int top;
} Stack;

// Initialize stack
void initStack(Stack *s) {
    s->top = -1;
}

// Push operation
void push(Stack *s, int value) {
    if (s->top == MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    s->data[++(s->top)] = value;
}

// Pop operation
int pop(Stack *s) {
    if (s->top == -1) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s->data[(s->top)--];
}

// Display stack
void display(Stack *s) {
    printf("Stack elements: ");
    for (int i = 0; i <= s->top; i++) {
        printf("%d ", s->data[i]);
    }
    printf("\n");
}

int main() {
    Stack s;
    initStack(&s);

    push(&s, 10);
    push(&s, 20);

    display(&s);

    printf("Popped element: %d\n", pop(&s));

    display(&s);

    return 0;
}
