#define MAX 10000  

typedef struct DLL {
    int key;
    int value;
    struct DLL* prev;
    struct DLL* next;
} DLL;

typedef struct {
    int capacity;
    int size;
    DLL* head;
    DLL* tail;
    DLL** hash;
} LRUCache;

void removeDLL(DLL* node) {
    node->prev->next = node->next;
    node->next->prev = node->prev;
}

void addToFront(LRUCache* cache, DLL* node) {
    node->next = cache->head->next;
    node->prev = cache->head;
    cache->head->next->prev = node;
    cache->head->next = node;
}

void moveToFront(LRUCache* cache, DLL* node) {
    removeDLL(node);
    addToFront(cache, node);
}

DLL* createDLL(int key, int value) {
    DLL* node = (DLL*)malloc(sizeof(DLL));
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
    cache->head = createDLL(0, 0); 
    cache->tail = createDLL(0, 0);  
    cache->head->next = cache->tail;
    cache->tail->prev = cache->head;
    cache->hash = (DLL**)calloc(MAX, sizeof(DLL*));  
    return cache;
}

int lRUCacheGet(LRUCache* obj, int key) {
    DLL* node = obj->hash[key];
    if (node) {
        moveToFront(obj, node);
        return node->value;
    }
    return -1;
}

void lRUCachePut(LRUCache* obj, int key, int value) {
    DLL* node = obj->hash[key];
    if (node) {
        node->value = value;
        moveToFront(obj, node);
    } else {
        if (obj->size == obj->capacity) {
            DLL* tail = obj->tail->prev;
            removeDLL(tail);
            obj->hash[tail->key] = NULL;
            free(tail);
            obj->size--;
        }
        DLL* newNode = createDLL(key, value);
        obj->hash[key] = newNode;
        addToFront(obj, newNode);
        obj->size++;
    }
}

void lRUCacheFree(LRUCache* obj) {
    DLL* current = obj->head;
    while (current) {
        DLL* next = current->next;
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
