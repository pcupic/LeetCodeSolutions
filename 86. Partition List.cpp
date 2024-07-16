/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x){

    struct ListNode* list1 = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    struct ListNode* list2 = (struct ListNode*)calloc(1, sizeof(struct ListNode));

    struct ListNode* l1 = list1;
    struct ListNode* l2 = list2;

    while(head) {
        if(head->val < x) {
            l1->next = head;
            l1 = l1->next;
        }
        else {
            l2->next = head;
            l2 = l2->next;
        }
        head = head->next;
    }

    l1->next = list2->next;
    l2 ->next = NULL;

    return list1->next;
}
