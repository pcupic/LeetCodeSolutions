/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}


struct TreeNode* buildUtil(int in[], int post[], int inStrt, int inEnd, int* pIndex) {
    if(inStrt > inEnd) return NULL;
    struct TreeNode* node = newNode(post[(*pIndex)]);
    (*pIndex)--;
    if(inStrt == inEnd) return node;
    int iIndex = search(in, inStrt, inEnd, node->val);
    node->right = buildUtil(in, post, iIndex + 1, inEnd, pIndex);
    node->left = buildUtil(in, post, inStrt, iIndex - 1, pIndex);
    return node;
}


int search(int* arr, int start, int end, int value) {
    int i;
    for(i = start; i <= end; i++) {
        if(arr[i] == value) 
            break;
    }
    return i;
}


struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int pIndex = inorderSize - 1;
    struct TreeNode* root = buildUtil(inorder, postorder, 0, inorderSize - 1, &pIndex);
    return root;
}
