#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode {
	int value;
	struct treeNode* left;
	struct treeNode* right;
} TreeNode;

TreeNode* createNode(int value) {
	TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
	node->value = value;
	node->left = NULL;
	node->right = NULL;
	return node;
}

void insertNode(TreeNode** root, int key) {
	if(*root == NULL) {
		*root = createNode(key);
		return;
	} 
	if((*root)->value == key) 
		return;
	else if((*root)->value < key) 
		insertNode(&(*root)->right, key);
	else 
		insertNode(&(*root)->left, key);
}

TreeNode* search(TreeNode* root, int criteria) {
	if(root == NULL || root->value == criteria)
		return root;
	if(root->value < criteria) 
		return search(root->right, criteria);
	return search(root->left, criteria);
}

TreeNode* findSuccessor(TreeNode* root) {
	TreeNode* temp = root->right;
	while(!temp && !temp->left)
		temp = temp->left;
	return temp;
}

TreeNode* deleteNode(TreeNode* root, int criteria) {
	if(root == NULL) 
		return root;
	if(root->value < criteria) 
		root->right = deleteNode(root->right, criteria);
	else if(root->value > criteria)
		root->left = deleteNode(root->left, criteria);
	else {
		if(!root->left) {
			TreeNode* temp = root->right;
			free(root);
			return temp;
		} 
		if(!root->right) {
			TreeNode* temp = root->left;
			free(root);
			return temp;
		}
		TreeNode* successor = findSuccessor(root);
		root->value = successor->value;
		root->right = deleteNode(root->right, successor->value);
	}
	return root;
}

void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    printf("%d ", root->value);
    inorder(root->right);
}

void preorder(TreeNode* root) {
    if (!root) return;
    printf("%d ", root->value);
    preorder(root->left);
    preorder(root->right);
}

void postorder(TreeNode* root) {
    if (!root) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->value);
}

int main() {
     TreeNode* root = NULL;
    insertNode(&root, 50);
    insertNode(&root, 30);
    insertNode(&root, 20);
    insertNode(&root, 40);
    insertNode(&root, 70);
    insertNode(&root, 60);
    insertNode(&root, 80);

    printf("Preorder traversal:\n");
    preorder(root);
    printf("\n");

    printf("Inorder traversal:\n");
    inorder(root);
    printf("\n");

    printf("Postorder traversal:\n");
    postorder(root);
    printf("\n");

    printf("Deleting 20\n");
    root = deleteNode(root, 20);
    inorder(root);
    printf("\n");

    printf("Deleting 30\n");
    root = deleteNode(root, 30);
    inorder(root);
    printf("\n");

    printf("Deleting 50\n");
    root = deleteNode(root, 50);
    inorder(root);
    printf("\n");

    return 0;

    return 0;
}
