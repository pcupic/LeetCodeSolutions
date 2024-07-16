/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX 10000

typedef struct stack {
    int V[MAX];
    int sp;
} Stack;

Stack* initialize_stack() {
    Stack *s = (Stack*)calloc(1, sizeof(Stack));
    s->sp = -1;
    return s;
}

void push(Stack *s, int x) {
    if(s->sp == MAX) {
        perror("Overflow");
        exit(1);
    }

    s->V[++s->sp] = x;
}

int pop(Stack *s) {
    if(s->sp == -1) {
        perror("Underflow");
        exit(1);
    }
    int x = s->V[s->sp--];
    return x;
}

int top(Stack *s) {
    return s->V[s->sp];
}

void clear(Stack *s) {
    s->sp = -1;
}

int is_empty(Stack *s) {
    return s->sp == -1;
}

int* dailyTemperatures(int* temperatures, int n, int* returnSize){

    Stack* s = initialize_stack();
    int* ans = (int*)calloc(n, sizeof(int));

    for (int i = n - 1; i >= 0; i--) {
        while (!is_empty(s) && temperatures[top(s)] <= temperatures[i]) {
            int x = pop(s);
        }
        ans[i] = is_empty(s) ? 0 : (top(s) - i);
        push(s, i);
    }

    *returnSize = n;
    return ans;
}
