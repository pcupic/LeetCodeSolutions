typedef struct {
    int* data;
    int size;
    int capacity;
} PriorityQueue;

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapifyUp(PriorityQueue* pq, int index) {
    if (index && pq->data[(index - 1) / 2] < pq->data[index]) {
        swap(&pq->data[(index - 1) / 2], &pq->data[index]);
        heapifyUp(pq, (index - 1) / 2);
    }
}

void heapifyDown(PriorityQueue* pq, int index) {
    int largest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < pq->size && pq->data[left] > pq->data[largest]) largest = left;
    if (right < pq->size && pq->data[right] > pq->data[largest]) largest = right;
    if (largest != index) {
        swap(&pq->data[largest], &pq->data[index]);
        heapifyDown(pq, largest);
    }
}

void resize(PriorityQueue* pq) {
    pq->capacity *= 2;
    pq->data = realloc(pq->data, pq->capacity * sizeof(int));
    if (!pq->data) {
        perror("Failed to reallocate memory");
        exit(1);
    }
}

void enqueue(PriorityQueue* pq, int value) {
    if (pq->size == pq->capacity) {
        resize(pq);
    }
    pq->data[pq->size++] = value;
    heapifyUp(pq, pq->size - 1);
}

int dequeue(PriorityQueue* pq) {
    if (!pq->size) {
        perror("Queue underflow");
        exit(1);
    }
    int item = pq->data[0];
    pq->data[0] = pq->data[--pq->size];
    heapifyDown(pq, 0);
    return item;
}

PriorityQueue* createPriorityQueue(int capacity) {
    PriorityQueue* pq = (PriorityQueue*)malloc(sizeof(PriorityQueue));
    pq->data = (int*)malloc(capacity * sizeof(int));
    pq->size = 0;
    pq->capacity = capacity;
    return pq;
}

void freePriorityQueue(PriorityQueue* pq) {
    free(pq->data);
    free(pq);
}

void printArray(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void wiggleSort(int* nums, int numsSize) {
    PriorityQueue* pq = createPriorityQueue(numsSize);

    for (int i = 0; i < numsSize; i++) {
        enqueue(pq, nums[i]);
    }

    for (int i = 1; i < numsSize; i += 2) {
        if (pq->size > 0) {
            nums[i] = dequeue(pq);
        }
    }
    for (int i = 0; i < numsSize; i += 2) {
        if (pq->size > 0) {
            nums[i] = dequeue(pq);
        }
    }

    freePriorityQueue(pq);
}
