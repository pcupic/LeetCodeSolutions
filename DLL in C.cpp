#include <stdio.h>
#include <stdlib.h>

typedef struct dllist {
	int value;
	struct dllist* previous;
	struct dllist* next;
} DLL;

DLL* createDLList(int value) {
	DLL* headNode = (DLL*)calloc(1, sizeof(DLL));
	if(headNode == NULL) {
		perror("Error creating DLL");
		return NULL;
	}
	headNode->value = value;
	return headNode;
}

void insertNodeDLListAtStart(DLL** head_ref, int value) {
	DLL* newNode = (DLL*)calloc(1, sizeof(DLL));
	newNode->value = value;
	if(newNode == NULL) {
		perror("Error creating new DLL Node");
		return;
	}
	newNode->next = *head_ref;
	(*head_ref)->previous = newNode;
	*head_ref = newNode;
}

void insertNodeDLListAtEnd(DLL* headNode, int value) {
	DLL* tempNode = headNode;
	DLL* newNode = (DLL*)calloc(1, sizeof(DLL));
	newNode->value = value;
	while(tempNode->next) {
			tempNode = tempNode->next;
	}
	tempNode->next = newNode;
	newNode->previous = tempNode;
}

void traverseDLList(DLL* headNode) {
	DLL* tempNode = headNode;
	if(!tempNode) return;

	while(tempNode) {
		printf("%d ", tempNode->value);
		tempNode = tempNode->next;
	} 
	printf("\n");
} 

DLL* searchDLList(DLL* headNode, int criteria) {
	DLL* tempNode = headNode;
	while(tempNode) {
		if(tempNode->value == criteria) return tempNode;
		tempNode = tempNode->next;
	}
	return NULL;
}

void deleteNodeDLList(DLL** head_ref, DLL* targetNode) {
	if(targetNode == NULL) {
		perror("Target node does not exist");
		return;
	}
	if((*head_ref) == targetNode) {
		(*head_ref) = (*head_ref)->next;
		(*head_ref)->previous = NULL;
		free(targetNode);
	}
	else if(targetNode->next == NULL) {
		targetNode = targetNode->previous;
		free(targetNode->next);
		targetNode->next = NULL;
	}
	else {
		targetNode->previous->next = targetNode->next;
		targetNode->next->previous = targetNode->previous;
		free(targetNode);
	}
}

DLL* deleteDLList(DLL* headNode) {
	DLL* deleteNode = NULL;
	while(headNode) {
		deleteNode = headNode;
		headNode = headNode->next;
		free(deleteNode);
	}
	return NULL;
}

int main(void) {

	DLL* headNode = createDLList(10);
    insertNodeDLListAtStart(&headNode, 5);
    insertNodeDLListAtEnd(headNode, 15);
    insertNodeDLListAtEnd(headNode, 20);

    printf("List after insertions: ");
    traverseDLList(headNode);

    DLL* searchResult = searchDLList(headNode, 15);
    printf("Found node with value 15 %s\n", searchResult ? "found" : "not found");

    deleteNodeDLList(&headNode, searchResult);
    printf("List after deleting node with value 15: ");
    traverseDLList(headNode);

    headNode = deleteDLList(headNode);
	if (headNode == NULL) {
        printf("List successfully deleted.\n");
    }

	return 0;
}
