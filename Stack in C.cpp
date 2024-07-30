#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int sp;
    int capacity;
} Stack;

Stack* createStack(int capacity) {
    Stack* s = (Stack*)malloc(sizeof(Stack));
    if (s == NULL) {
        perror("Stack allocation error");
        exit(1);
    }
    s->data = (int*)malloc(capacity * sizeof(int));
    if (s->data == NULL) {
        free(s);
        perror("Data allocation error");
        exit(1);
    }
    s->sp = -1;
    s->capacity = capacity;
    return s;
}

void freeStack(Stack* s) {
    free(s->data);
    free(s);
}

int isEmpty(Stack* s) { return s->sp == -1; }

int isFull(Stack* s) { s->sp == s->capacity - 1; }

void push(Stack* s, int value) {
    if (isFull(s)) {
        s->capacity *= 2;
        int *newData = (int*)realloc(s->data, s->capacity * sizeof(int));
        if (newData == NULL) {
            perror("Stack overflow");
            freeStack(s);
            exit(1);
        }
        s->data = newData;
    }
    s->data[++s->sp] = value;
}

int pop(Stack* s) {
    if (isEmpty(s)) {
        perror("Stack underflow");
        exit(1);
    }
    return s->data[s->sp--];
}

int top(Stack* s) {
    if (isEmpty(s)) {
        perror("Stack is empty");
        exit(1);
    }
    return s->data[s->sp];
}

int main(void) {

    Stack* stack = createStack(2);

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        push(stack, arr[i]);
    }

    printf("Top element is %d\n", top(stack));

    printf("Popped elements:\n");
    while (!isEmpty(stack)) {
        printf("%d ", pop(stack));
    }
    printf("\n");

    freeStack(stack); 
    return 0;
}
