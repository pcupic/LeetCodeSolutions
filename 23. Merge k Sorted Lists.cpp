/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAX 10000

typedef struct {
	int data[MAX];
	int size;
} PriorityQueue;

void swap(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

struct ListNode* createNode(int val) {
    struct ListNode* newNode = malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

PriorityQueue* createPriorityQueue() {
    return (PriorityQueue*)calloc(1, sizeof(PriorityQueue));
}

void heapifyUp(PriorityQueue* pq, int index) {
	if(index && pq->data[(index - 1) / 2] > pq->data[index]) {
		swap(&pq->data[(index - 1) / 2], &pq->data[index]);
		heapifyUp(pq, (index - 1) / 2);
	}
}

void enqueue(PriorityQueue* pq, int value) {
	if(pq->size == MAX) {
		perror("Queue overlflow");
		exit(1);
	}
	pq->data[pq->size++] = value;
	heapifyUp(pq, pq->size - 1);
}

void heapifyDown(PriorityQueue* pq, int index) {
	int smallest = index;
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	
	if(left < pq->size && pq->data[left] < pq->data[smallest]) smallest = left;
	if(right < pq->size && pq->data[right] < pq->data[smallest]) smallest = right;
	if(smallest != index) {
		swap(&pq->data[smallest], &pq->data[index]);
		heapifyDown(pq, smallest);
	}
}

int dequeue(PriorityQueue* pq) {
	if(!pq->size) {
		perror("Queue underflow");
		exit(1);
	}
	int item = pq->data[0];
	pq->data[0] = pq->data[--pq->size];
	heapifyDown(pq, 0);
	return item;
}

int peek(PriorityQueue* pq) {
	if(!pq->size) {
		perror("Queue empty");
		exit(1);
	}
	return pq->data[0];
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    PriorityQueue* pq = createPriorityQueue();
    for(int i = 0; i < listsSize; i++) {
        struct ListNode* temp = lists[i];
        while(temp) {
            enqueue(pq, temp->val);
            temp = temp->next;
        }
    }

    struct ListNode* headNode = NULL;
    struct ListNode* current = headNode;

    while(!isEmpty(pq)) {
        struct ListNode* temp = createNode(dequeue(pq));
        if(!headNode) {
            headNode = temp;
            current = temp;
        }
        else {
            current->next = temp;
            current = current->next;
        }
    }
    
    return headNode;
}
