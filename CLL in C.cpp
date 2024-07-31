#include <stdio.h>
#include <stdlib.h>

typedef struct cllist {
	int value;
	struct cllist* next;
} CLL;

CLL* createCLList(int value) {
	CLL* headNode = (CLL*)calloc(1, sizeof(CLL));
	if(headNode == NULL) {
		perror("Error creating CLL");
		return NULL;
	}
	headNode->value = value;
	headNode->next = headNode;
	return headNode;
}

void insertNodeCLList(CLL* headNode, int value) {
	CLL* newNode = (CLL*)calloc(1, sizeof(CLL));
	if(newNode == NULL) {
		perror("Error creating new CLL node");
		return;
	}
	newNode->value = value;
	newNode->next = headNode;
	CLL* tempNode = headNode;
	while(tempNode->next != headNode) 
		tempNode = tempNode->next;
	tempNode->next = newNode;
}

void traverseCLList(CLL* headNode) {
	if(headNode == NULL) return;
	CLL* tempNode = headNode->next;
	printf("%d ", headNode->value);
	while(tempNode != headNode) {
		printf("%d ", tempNode->value);
		tempNode = tempNode->next;
	}
}

CLL* searchCLList(CLL* headNode, int criteria) {
	CLL* tempNode = headNode;
	if(tempNode->value == criteria) return tempNode;
    else {
    	tempNode = tempNode->next;
    	while(tempNode != headNode) {
        	if (tempNode->value == criteria) {
           		return tempNode;
        	}
       		tempNode = tempNode->next;
    	}
	}
    return NULL;
}

void deleteNodeCLList(CLL** headNode, CLL* targetNode) {
	if(targetNode == NULL) {
		perror("Target node does not exist");
		return;
	}
	CLL* tempNode = *headNode;
	if(*headNode == targetNode) {
		while(tempNode->next != *headNode) 
			tempNode = tempNode->next;
		tempNode->next = (*headNode)->next;
		*headNode = tempNode->next;
		free(targetNode);
	}
	else if(targetNode->next == *headNode) {
		while(tempNode->next != targetNode) 
			tempNode = tempNode->next;
		tempNode->next = targetNode->next;
		free(targetNode);
	}
	else {
		while(tempNode->next != *headNode) {
			if(tempNode->next == targetNode) {
				tempNode->next = targetNode->next;
				free(targetNode);
				break;
			}
			tempNode = tempNode->next;
		}
	}
}

CLL* deleteCLList(CLL* headNode) {
	if(headNode == NULL) return NULL;
	CLL* tempNode = headNode;
	CLL* nextNode = NULL;
	do {
		nextNode = tempNode->next;
		free(tempNode);
		tempNode = tempNode->next;
	} while(tempNode != headNode);
	
	return NULL;
}

int main(void){
    CLL* head = createCLList(10);
    
    insertNodeCLList(head, 20);
    insertNodeCLList(head, 30);
    
    printf("List contents: ");
    traverseCLList(head);
    
    CLL* node = searchCLList(head, 20);
    if (node != NULL) {
        printf("\nFound node with value %d", node->value);
    } else {
        printf("\nNode with value 20 not found");
    }
    
    deleteNodeCLList(&head, node);
    
    printf("\nList contents after deletion: ");
    traverseCLList(head);
    
   	head = deleteCLList(head);
	if (head == NULL) {
        printf("\nList successfully deleted.\n");
    }
    
	return 0;
}
