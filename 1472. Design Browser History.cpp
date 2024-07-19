typedef struct Node {
    char* url;
    struct Node* prev;
    struct Node* next;
} Node;

typedef struct {
    Node* current;
} BrowserHistory;

Node* createNode(char* url) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->url = strdup(url);
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

BrowserHistory* browserHistoryCreate(char* homepage) {
    BrowserHistory* history = (BrowserHistory*)malloc(sizeof(BrowserHistory));
    history->current = createNode(homepage);
    return history;
}

void browserHistoryVisit(BrowserHistory* obj, char* url) {
    Node* newNode = createNode(url);
    obj->current->next = newNode;
    newNode->prev = obj->current;
    obj->current = newNode;
}

char* browserHistoryBack(BrowserHistory* obj, int steps) {
    while (steps > 0 && obj->current->prev != NULL) {
        obj->current = obj->current->prev;
        steps--;
    }
    return obj->current->url;
}

char* browserHistoryForward(BrowserHistory* obj, int steps) {
    while (steps > 0 && obj->current->next != NULL) {
        obj->current = obj->current->next;
        steps--;
    }
    return obj->current->url;
}

void browserHistoryFree(BrowserHistory* obj) {
    Node* temp;
    while (obj->current->prev != NULL) {
        obj->current = obj->current->prev;
    }
    while (obj->current != NULL) {
        temp = obj->current;
        obj->current = obj->current->next;
        free(temp->url);
        free(temp);
    }
    free(obj);
}


/**
 * Your BrowserHistory struct will be instantiated and called as such:
 * BrowserHistory* obj = browserHistoryCreate(homepage);
 * browserHistoryVisit(obj, url);
 
 * char* param_2 = browserHistoryBack(obj, steps);
 
 * char* param_3 = browserHistoryForward(obj, steps);
 
 * browserHistoryFree(obj);
*/
