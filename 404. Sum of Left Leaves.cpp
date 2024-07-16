/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void sumOfLeftLeavesHelper(struct TreeNode* root, bool isLeft, int* sum) {
    if (!root) return;

    if (isLeft && !root->left && !root->right) {
        (*sum) += root->val;
        return;
    }

    sumOfLeftLeavesHelper(root->left, true, sum);
    sumOfLeftLeavesHelper(root->right, false, sum);
}

int sumOfLeftLeaves(struct TreeNode* root) {
    int sum = 0;
    sumOfLeftLeavesHelper(root, false, &sum);
    return sum;
}
