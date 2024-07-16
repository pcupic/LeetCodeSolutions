#define MAX 10000

typedef struct {
    char data[MAX];
    int top;
} Stack;

void initialize(Stack *stack) {
    stack->top = -1;
}

void push(Stack *stack, char c) {
    if (stack->top < MAX - 1) {
        stack->data[++(stack->top)] = c;
    }
}

char pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[(stack->top)--];
    }
    return '\0'; 
}

int is_empty(Stack *stack) {
    return stack->top == -1;
}

bool isValid(char * s){

    Stack stack;
    initialize(&stack);

    for(int i = 0; s[i] != '\0'; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(&stack, s[i]);
        }
        else if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if(is_empty(&stack)) return false;
            char top = pop(&stack);
            if((s[i] == ')' && top != '(') ||
               (s[i] == ']' && top != '[') ||
               (s[i] == '}' && top != '{'))
                return false;
        }
    }

    return is_empty(&stack);
}
