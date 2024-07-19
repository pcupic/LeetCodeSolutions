#define MAX 10000

typedef struct Node {
    int key;
    int value;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    int capacity;
    int size;
    Node* head;
    Node* tail;
    Node** hash;
} LRUCache;

void removeNode(Node* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void addToFront(LRUCache* cache, Node* node) {
    node->next = cache->head->next;
    node->prev = cache->head;
    cache->head->next->prev = node;
    cache->head->next = node;
}

void moveToFront(LRUCache* cache, Node* node) {
    removeNode(node);
    addToFront(cache, node);
}

Node* createNode(int key, int value) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->value = value;
    node->prev = NULL;
    node->next = NULL;
    return node;
}

LRUCache* lRUCacheCreate(int capacity) {
    LRUCache* cache = (LRUCache*)malloc(sizeof(LRUCache));
    cache->capacity = capacity;
    cache->size = 0;
    cache->head = createNode(0, 0);  
    cache->tail = createNode(0, 0);  
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;
    cache->hash = (Node**)calloc(MAX, sizeof(Node*));  
    return cache;
}

int lRUCacheGet(LRUCache* obj, int key) {
    Node* node = obj->hash[key];
    if (node) {
        moveToFront(obj, node);
        return node->value;
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    Node* node = obj->hash[key];
    if (node) {
        node->value = value;
        moveToFront(obj, node);
    } else {
        if (obj->size == obj->capacity) {
            Node* tail = obj->tail->prev;
            removeNode(tail);
            obj->hash[tail->key] = NULL;
            free(tail);
            obj->size--;
        }
        Node* newNode = createNode(key, value);
        obj->hash[key] = newNode;
        addToFront(obj, newNode);
        obj->size++;
    }
}

void lRUCacheFree(LRUCache* obj) {
    Node* current = obj->head;
    while (current) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    free(obj->hash);
    free(obj);
}

/**
 * Your LRUCache struct will be instantiated and called as such:
 * LRUCache* obj = lRUCacheCreate(capacity);
 * int param_1 = lRUCacheGet(obj, key);
 
 * lRUCachePut(obj, key, value);
 
 * lRUCacheFree(obj);
*/
