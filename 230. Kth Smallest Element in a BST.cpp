/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int countNodes(struct TreeNode* root) {
    if(!root) return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

void inorder(struct TreeNode* root, int* ans, int* index) {
    if(!root) return;
    inorder(root->left, ans, index);
    ans[(*index)++] = root->val;
    inorder(root->right, ans, index);
}

int kthSmallest(struct TreeNode* root, int k) {
    int* ans = (int*)malloc(countNodes(root) * sizeof(int));
    int index = 0;
    inorder(root, ans, &index);
    return ans[k - 1];
}
