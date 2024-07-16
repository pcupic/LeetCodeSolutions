/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



struct TreeNode* searchBST(struct TreeNode* root, int key) {
    if(!root || root->val == key) return root;
    if(root->val < key) return searchBST(root->right, key);
    return searchBST(root->left, key);
}
