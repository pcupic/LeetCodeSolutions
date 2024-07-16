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

void postorder(struct TreeNode* root, int* ans, int* index) {
    if(!root) return;
    postorder(root->left, ans, index);
    postorder(root->right, ans, index);
    ans[(*index)++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize) {
    int* ans = (int*)malloc(countNodes(root) * sizeof(int));
    *returnSize = 0;
    postorder(root, ans, returnSize);
    return ans;   
}
