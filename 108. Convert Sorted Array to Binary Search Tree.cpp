/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* buildTree(int* nums, int start, int end) {
    if(start > end) 
        return NULL;
    
    int mid = (start + end) / 2;
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums[mid];
    root->left = buildTree(nums, start, mid - 1);
    root->right = buildTree(nums, mid + 1, end);
    return root;
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    return buildTree(nums, 0, numsSize - 1);
}


