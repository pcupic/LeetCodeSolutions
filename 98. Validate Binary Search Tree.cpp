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

int min(int a, int b) {
    return a < b ? a : b;
}

int maxValue(struct TreeNode* node) {
    if(node == NULL) return INT_MIN;
    int value = node->val;
    int leftMax = maxValue(node->left);
    int rightMax = maxValue(node->right);
    return max(value, max(leftMax, rightMax));
}

int minValue(struct TreeNode* node) {
    if(node == NULL) return INT_MAX;
    int value = node->val;
    int leftMin = minValue(node->left);
    int rightMin = minValue(node->right);
    return min(value, min(leftMin, rightMin));
}

bool isValidBST(struct TreeNode* root) {

    if(root == NULL) return true;  
    if(root->left != NULL && maxValue(root->left) >= root->val) 
        return false;
    if(root->right != NULL && minValue(root->right) <= root->val)
        return false;
    if(!isValidBST(root->left) || !isValidBST(root->right))
        return false;
    
    return true;
}
