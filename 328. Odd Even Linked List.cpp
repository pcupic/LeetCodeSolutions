/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head){

    if(head == NULL) return head;

    struct ListNode* odd = head;
    struct ListNode* even = head->next;
    struct ListNode* hold = head->next;

    while(even != NULL && even->next != NULL) {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = hold;

    return head;
}
