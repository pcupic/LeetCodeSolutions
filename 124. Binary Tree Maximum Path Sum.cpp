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

struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

int findMaxUtil(struct TreeNode* root, int* res) {
    if(root == NULL) return 0;
    int l = findMaxUtil(root->left, res);
    int r = findMaxUtil(root->right, res);
    int max_single = max(max(l, r) + root->val, root->val);
    int max_top = max(max_single, l + r + root->val);
    *res = max(*res, max_top);
    return max_single;
}

int maxPathSum(struct TreeNode* root) {
    int res = INT_MIN;
    findMaxUtil(root, &res);
    return res;
}
