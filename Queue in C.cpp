#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int size, front, rear;
    unsigned capacity;
    int *data;
} Queue;

Queue* createQueue(unsigned capacity) {
    Queue* q = (Queue*)calloc(1, sizeof(Queue));
    if (q == NULL) {
        perror("Queue allocation error");
        exit(1);
    }
    q->data = (int*)calloc(capacity, sizeof(int));
    if (q->data == NULL) {
        perror("Data allocation error");
        free(q);
        exit(1);
    }
    q->capacity = capacity;
    q->front = 0;
    q->rear = capacity - 1;
    q->size = 0;
    return q;
}


void freeQueue(Queue* q) {
    if(q) {
        free(q->data);
        free(q);
    }
}

int isFull(Queue* q) {
    return q->size == q->capacity;
}

int isEmpty(Queue* q) {
    return q->size == 0;
}

void resizeQueue(Queue* q) {
    int newCapacity = q->capacity * 2;
    int* newdata = (int*)realloc(q->data, newCapacity * sizeof(int));
    if (newdata == NULL) {
        perror("Reallocation error");
        freeQueue(q);
        exit(1);
    }
    
    if(q->front > q->rear) {
        for(int i = 0; i < q->front; i++) {
            newdata[i + q->capacity] = q->data[i];
        }
        q->rear += q->capacity;
    }
    
    q->data = newdata;
    q->capacity = newCapacity;
}

void enqueue(Queue* q, int item) {
    if (isFull(q)) {
        resizeQueue(q);
    }
    q->rear = (q->rear + 1) % q->capacity;
    q->data[q->rear] = item;
    q->size++;
}

int dequeue(Queue* q) {
    if (isEmpty(q)) {
        perror("Queue underflow");
        exit(1); 
    }
    int item = q->data[q->front];
    q->front = (q->front + 1) % q->capacity;
    q->size--;
    return item;
}

int front(Queue* q) {
    if (isEmpty(q)) {
        perror("Queue is empty");
        exit(1); 
    }
    return q->data[q->front];
}

int rear(Queue* q) {
    if(isEmpty(q)) {
        perror("Queue is empty");
        exit(1); 
    }
    return q->data[q->rear];
}

int main(void) {
	Queue* q = createQueue(2);

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);

    for (int i = 0; i < n; i++) {
        enqueue(q, arr[i]);
    }

    printf("Front element is %d\n", front(q));
    printf("Rear element is %d\n", rear(q));

    printf("Dequeued elements:\n");
    while (!isEmpty(q)) {
        printf("%d ", dequeue(q));
    }
    printf("\n");

    freeQueue(q); 
    return 0;
}


