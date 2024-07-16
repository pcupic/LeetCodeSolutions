/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head){

    struct ListNode* first = head;
    struct ListNode* dummy = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    struct ListNode* prev = dummy;
    prev->next = head;

    while(first != NULL && first->next != NULL) {
        struct ListNode* second = first->next;
        struct ListNode* future = second->next;
        second->next = first;
        prev->next = second;
        first->next = future;
        prev = first;
        first = future;
    }

    return dummy->next;
}
