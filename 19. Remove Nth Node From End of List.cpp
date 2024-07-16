/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n){

    struct ListNode* dummy = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* left = dummy;
    struct ListNode* right = head;

    for(int i = 0; i < n; i++) right = right->next;

    for(; right; right = right->next) left = left->next;

    left->next = left->next->next;

    return dummy->next;
}
