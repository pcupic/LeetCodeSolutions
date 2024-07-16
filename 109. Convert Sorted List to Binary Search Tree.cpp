/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
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

struct TreeNode* buildTree(int* arr, int start, int end) {
    if(start > end) return NULL;
    int mid = (start + end) / 2;
    struct TreeNode* node = newNode(arr[mid]);
    node->left = buildTree(arr, start, mid - 1);
    node->right = buildTree(arr, mid + 1, end);
    return node;
}

struct TreeNode* sortedListToBST(struct ListNode* head) {
    
    int n = 0;
    struct ListNode* temp = head;
    while(temp) {
        temp = temp->next;
        n++;
    }

    int* arr = (int*)calloc(n, sizeof(int));

    int i = 0;
    temp = head;
    while(temp) {
        arr[i++] = temp->val;
        temp = temp->next;
    }

    return buildTree(arr, 0, n - 1);
}
