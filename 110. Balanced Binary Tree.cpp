/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b) {
    return a > b ? a : b;
}

int calculateHeight(struct TreeNode* root) {
    if(!root) return 0;
    return 1 + max(calculateHeight(root->left), calculateHeight(root->right));
}

int bst(struct TreeNode* root, int* check) {
    if(root == NULL) return 0;
    int left = 1 + bst(root->left, check);
    int right = 1 + bst(root->right, check);
    if(abs(right - left) > 1) (*check) = 0;
    return max(left, right);
} 

bool isBalanced(struct TreeNode* root) {

   	if (!root) return true;

    int leftHeight = calculateHeight(root->left);
    int rightHeight = calculateHeight(root->right);

    if (abs(leftHeight - rightHeight) > 1) {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

