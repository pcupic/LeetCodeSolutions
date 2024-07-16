/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void findSum(struct TreeNode* root, int value, int* ans) {
    int current = value * 10 + root->val;
    if(!root->left && !root->right) {
        *ans += current;
        return;
    }
    if(root->left) findSum(root->left, current, ans);
    if(root->right) findSum(root->right, current, ans);
}

int sumNumbers(struct TreeNode* root) {
    if(!root) return 0;
    int ans = 0;
    findSum(root, 0, &ans);
    return ans;
}

