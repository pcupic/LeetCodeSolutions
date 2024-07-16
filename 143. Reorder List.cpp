/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAX 50000

typedef struct stack {
    int arr[MAX];
    int sp;
} Stack;

Stack* create_stack() {
    Stack* s = (Stack*)calloc(1, sizeof(Stack));
    s->sp = -1;
    return s;
}
void push(Stack* s, int x) {
    if(s->sp == MAX) {
        exit(1);
    }
    s->arr[++s->sp] = x;
}

int pop(Stack* s) {
    if(s->sp == -1) {
        exit(1);
    }
    int x = s->arr[s->sp--];
    return x;
}

int is_empty(Stack* s) {
    return s->sp == -1;
}

void clear(Stack* s) {
    s->sp = -1;
}

int top(Stack *s) {
    return s->arr[s->sp];
}

struct ListNode* search_node(int x, struct ListNode* node) {

    while(node) {
        if(node->val == x) 
            return node;
        node = node->next;
    }
    return NULL;
}

void reorderList(struct ListNode* head){

    struct ListNode* stack[MAX];
    struct ListNode* curr = head;
    struct ListNode* future;
    int x = 0;
    while(curr) {
        stack[x++] = curr;
        curr = curr->next;
    }

    curr = head;

    int n = x;

    for(int i = 0; i < n / 2; i++) {
        future = curr->next;
        curr->next = stack[--x];
        curr = curr->next;
        curr->next = future;
        curr = curr->next;
    }
    curr->next = NULL;
}
