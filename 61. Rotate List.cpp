/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k){

    if(head == NULL) return head;

    struct ListNode* temp = head;
    int n = 0;

    while(temp->next != NULL) {
        temp = temp->next;
        n++;
    }

    temp->next = head;

    k = k % (n + 1);
    int jump = n - k;
    temp = head;
    while(jump) {
        temp = temp->next;
        jump--;
    }

    struct ListNode* returnHead = temp->next;
    temp->next = NULL;

    return returnHead;
}
