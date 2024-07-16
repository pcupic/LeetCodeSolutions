/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define MAX 100

int countNodes(struct TreeNode* root) {
    if (root == NULL) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorder(struct TreeNode* root, int* output, int* length) {
    if(!root) return;
    inorder(root->left, output, length);
    output[(*length)++] = root->val;
    inorder(root->right, output, length);
} 

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    int* output = malloc(countNodes(root) * sizeof(int));
    inorder(root, output, returnSize);
    return output;
}
