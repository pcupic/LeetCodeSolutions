/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode* a, struct TreeNode* b) {
    if(a == NULL && b == NULL) return true;
    if(a && b && a->val == b->val) 
        return isMirror(a->left, b->right) && isMirror(a->right, b->left);
    return false;
}

bool isSymmetric(struct TreeNode* root) {
    return isMirror(root, root);
}
