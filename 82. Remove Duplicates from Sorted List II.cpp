/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* deleteDuplicates(struct ListNode* head){

    if(head == NULL) return head;

    struct ListNode* pseudo = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    pseudo->next = head;
    struct ListNode* temp = pseudo;

    while (temp->next && temp->next->next) {
        if (temp->next->val == temp->next->next->val) {
            int duplicate = temp->next->val;
            while (temp->next != NULL && temp->next->val == duplicate) {
                temp->next = temp->next->next;
            }
        } else {
            temp = temp->next;
        }
    }

    return pseudo->next;
}
