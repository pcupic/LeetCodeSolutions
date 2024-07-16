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

int countNodes(struct TreeNode* root) {
    if(!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void preorder(struct TreeNode* root, int* ans, int* index) {
    if(!root) return;
    ans[(*index)++] = root->val;
    preorder(root->left, ans, index);
    preorder(root->right, ans, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    int nodesCount = countNodes(root);
    int* ans = (int*)malloc((nodesCount) * sizeof(int));
    *returnSize = 0;
    preorder(root, ans, returnSize);
   
    return ans;
}
