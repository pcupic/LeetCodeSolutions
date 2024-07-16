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

int largestRectangleArea(int* heights, int n){
    Stack *s = initialize_stack();
    int left[n];
    int right[n];
    int max_area = 0;

    for(int i = 0; i < n; i++) {
        if(is_empty(s)) {
            left[i] = 0;
        }
        else if(heights[i] <= heights[top(s)]) {
            while(!is_empty(s) && heights[i] <= heights[top(s)]) {
                int x = pop(s);
            }
            if(is_empty(s)) {
                left[i] = 0;
            }
            else {
                left[i] = top(s) + 1;
            }
        }
        else {
            left[i] = top(s) + 1;
        }
        push(s, i);
    }

    clear(s);

    for(int i = n - 1; i >= 0; i--) {
        if(is_empty(s)) {
            right[i] = n - 1;
        }
        else if(heights[i] <= heights[top(s)]) {
            while(!is_empty(s) && heights[i] <= heights[top(s)]) {
                int x = pop(s);
            }
            if(is_empty(s)) {
                right[i] = n - 1;
            }
            else {
                right[i] = top(s) - 1;
            }
        }
        else {
            right[i] = top(s) - 1;
        }
        push(s, i);
    }

    for(int i = 0; i < n; i++) {
        if(((right[i] - left[i] + 1) * heights[i]) > max_area) {
            max_area = (right[i] - left[i] + 1) * heights[i];
        }
    }

    return max_area;
}
