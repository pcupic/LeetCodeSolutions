/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapNodes(struct ListNode* head, int k){

    int length = 0;
    struct ListNode* curr = head;
    struct ListNode* frontNode = head;
    struct ListNode* endNode = head;

    while(curr != NULL) {
        length++;
        if(length == k) {
            frontNode = curr;
        }
        curr = curr->next;
    }

    for(int i = 0; i < length - k; i++) endNode = endNode->next;

    int temp = frontNode->val;
    frontNode->val = endNode->val;
    endNode->val = temp;

    return head;

    
}
