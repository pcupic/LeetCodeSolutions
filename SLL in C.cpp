#include <stdio.h>
#include <stdlib.h>

typedef struct sll {
	int value;
	struct sll* next;
} SLL;

SLL* createSLList(int value) {
	SLL* headNode = (SLL*)calloc(1, sizeof(SLL));
	if(headNode == NULL) {
		perror("Error creating SLL");
		return NULL;
	}
	else headNode->value = value;
	return headNode;
}

void insertNodeSLListAtStart(SLL** head_ref, int value) {
	SLL* newNode = (SLL*)calloc(1, sizeof(SLL));
	if(newNode == NULL) {
		perror("Error creating new SLL node");
		return;
	}
	else {
		newNode->value = value;
		newNode->next = *head_ref;
		*head_ref = newNode;
	}
}

void insertNodeSLListAtEnd(SLL* headNode, int value) {
	SLL* newNode = (SLL*)calloc(1, sizeof(SLL));
	if(newNode == NULL) {
		perror("Error creating new SLL node");
		return;
	}
	else {
		newNode->value = value;
		SLL* tempNode = headNode;
		while(tempNode->next) {
			tempNode = tempNode->next;
		}
		tempNode->next = newNode;
	}
}

void traverseSLList(SLL* headNode) {
	SLL* tempNode = headNode;
	if(!tempNode) return;

	while(tempNode) {
		printf("%d ", tempNode->value);
		tempNode = tempNode->next;
	} 
	printf("\n");
} 

SLL* searchSLList(SLL* headNode, int criteria) {
	SLL* tempNode = headNode;
	while(tempNode) {
		if(tempNode->value == criteria) return tempNode;
		tempNode = tempNode->next;
	}
	return NULL;
}

void deleteNodeSLList(SLL** head_ref, SLL* targetNode) {
    if (targetNode == NULL) {
        perror("Target node does not exist");
        return;
    }
    if (*head_ref == targetNode) {
        *head_ref = (*head_ref)->next;
        free(targetNode);
    } else {
        SLL* tempNode = *head_ref;
        while (tempNode->next) {
            if (tempNode->next == targetNode) {
                tempNode->next = targetNode->next;
                free(targetNode);
                break;
            }
            tempNode = tempNode->next;
        }
    }
}
SLL* deleteSLList(SLL* headNode) {
	SLL* deleteNode = NULL;
	while(headNode) {
		deleteNode = headNode;
		headNode = headNode->next;
		free(deleteNode);
	}
	return NULL;
}

int main(void) {

    SLL* headNode = createSLList(5);
    if (headNode == NULL) {
        return 1;
    }

    insertNodeSLListAtStart(&headNode, 3);
    insertNodeSLListAtStart(&headNode, 1);

    insertNodeSLListAtEnd(headNode, 7);
    insertNodeSLListAtEnd(headNode, 9);

    printf("List after insertions: ");
    traverseSLList(headNode);

	SLL* foundNode = searchSLList(headNode, 8);
	printf("Node with value 8 %s.\n", foundNode ? "found" : "not found");
    foundNode = searchSLList(headNode, 3);
	printf("Node with value 3 %s.\n", foundNode ? "found" : "not found");

    deleteNodeSLList(&headNode, foundNode);
    printf("List after deleting node with value 3: ");
    traverseSLList(headNode);

    headNode = deleteSLList(headNode);

    if (headNode == NULL) {
        printf("List successfully deleted.\n");
    }

    return 0;
}
