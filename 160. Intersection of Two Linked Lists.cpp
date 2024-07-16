/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    
    if (!headA || !headB) return NULL;

    struct ListNode* first = headA;
    struct ListNode* second = headB;

    while (first != second) {
        first = first ? first->next : headB;
        second = second ? second->next : headA;
    }

    return first;  
}
