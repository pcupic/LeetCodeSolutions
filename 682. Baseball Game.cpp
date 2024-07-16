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


int calPoints(char ** operations, int operationsSize){

  
    Stack* s = initialize_stack();
    for(int i = 0; i < operationsSize; i++) {
        switch(*operations[i]) {
            case 'C': 
                if(!is_empty(s)) {
                    int x = pop(s);
                }
                break;
            case 'D': 
                push(s, 2 * top(s));
                break;
            case '+': 
                int val1 = top(s);
                int x = pop(s);
                int val2 = top(s);
                x = pop(s);
                push(s, val2);
                push(s, val1);
                push(s, val1 + val2);
                break;
            default:
                push(s, atoi(operations[i]));
        }
    }

    int num = 0;
    while(!is_empty(s)) {
        num += pop(s);
    }

    return num;
}   
