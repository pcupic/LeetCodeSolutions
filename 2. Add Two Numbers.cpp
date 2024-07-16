/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){

    struct ListNode* temp = (struct ListNode*)calloc(1, sizeof(struct ListNode)); 
    struct ListNode* l3 = temp;
    int carry = 0;

    while (l1 || l2 || carry) {
        int value = carry;
        
        if (l1) {
            value += l1->val;
            l1 = l1->next;
        }
        if (l2) {
            value += l2->val;
            l2 = l2->next;
        }
        
        carry = value / 10;
        
        l3->next = (struct ListNode*)calloc(1, sizeof(struct ListNode));
        l3 = l3->next;
        l3->val = value % 10;
    }

    return temp->next;
}
