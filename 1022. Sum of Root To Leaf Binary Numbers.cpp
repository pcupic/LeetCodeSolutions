/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int sumRootToLeafHelper(struct TreeNode* root, int sum) {
    if(!root) return 0;
    sum = (sum << 1) + root->val;
    if(!root->left && !root->right) return sum;
    return sumRootToLeafHelper(root->left, sum) + sumRootToLeafHelper(root->right, sum);
}

int sumRootToLeaf(struct TreeNode* root) {
    return sumRootToLeafHelper(root, 0);
}
