/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void recoverTree(struct TreeNode* root) {
    struct TreeNode *first = NULL;
    struct TreeNode *second = NULL;
    struct TreeNode *prev = NULL;
    struct TreeNode *current = root;
    struct TreeNode *stack[1000]; 
    int top = -1;

    while (current != NULL || top != -1) {
        while (current != NULL) {
            stack[++top] = current;
            current = current->left;
        }
        current = stack[top--];

        if (prev != NULL && prev->val > current->val) {
            if (first == NULL) {
                first = prev;
                second = current;
            } else {
                second = current;
                break;
            }
        }
        prev = current;
        current = current->right;
    }

    if (first != NULL && second != NULL) {
        swap(&(first->val), &(second->val));
    }
}
