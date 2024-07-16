/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* newNode(int data) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct TreeNode* build(int* nums, int i, int j) {
    if(i > j) return NULL;

    int maxNum = INT_MIN;
    int maxIndex = 0;
    for(int k = i; k <= j; k++) {
        if(nums[k] > maxNum) {
            maxNum = nums[k];
            maxIndex = k;
        }
    }

    struct TreeNode* root = newNode(maxNum);
    root->left = build(nums, i, maxIndex - 1);
    root->right = build(nums, maxIndex + 1, j);
    return root;
}

struct TreeNode* constructMaximumBinaryTree(int* nums, int numsSize) {
    return build(nums, 0, numsSize - 1);
}
