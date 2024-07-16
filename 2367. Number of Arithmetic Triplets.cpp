#define TABLE_SIZE 10000

typedef struct HashNode {
    int key;
    struct HashNode* next;
} HashNode;

typedef struct {
    HashNode* table[TABLE_SIZE];
} HashTable;

int hashFunction(int key) {
    return abs(key) % TABLE_SIZE;
}

HashTable* createHashTable() {
    HashTable* hashTable = (HashTable*)malloc(sizeof(HashTable));
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable->table[i] = NULL;
    }
    return hashTable;
}

void insert(HashTable* hashTable, int key) {
    int hashIndex = hashFunction(key);
    HashNode* newNode = (HashNode*)malloc(sizeof(HashNode));
    newNode->key = key;
    newNode->next = hashTable->table[hashIndex];
    hashTable->table[hashIndex] = newNode;
}

bool search(HashTable* hashTable, int key) {
    int hashIndex = hashFunction(key);
    HashNode* node = hashTable->table[hashIndex];
    while (node != NULL) {
        if (node->key == key) {
            return true;
        }
        node = node->next;
    }
    return false;
}

void freeHashTable(HashTable* hashTable) {
    for (int i = 0; i < TABLE_SIZE; i++) {
        HashNode* node = hashTable->table[i];
        while (node != NULL) {
            HashNode* temp = node;
            node = node->next;
            free(temp);
        }
    }
    free(hashTable);
}

int arithmeticTriplets(int* nums, int numsSize, int diff) {
    HashTable* hashTable = createHashTable();
    int ans = 0;

    for (int i = 0; i < numsSize; i++) {
        insert(hashTable, nums[i]);
    }

    for (int i = 0; i < numsSize; i++) {
        if (search(hashTable, nums[i] - diff) && search(hashTable, nums[i] - 2 * diff)) {
            ans++;
        }
    }

    freeHashTable(hashTable);
    return ans;
}
