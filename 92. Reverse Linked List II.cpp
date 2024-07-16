/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define MAX 500

struct ListNode* reverseBetween(struct ListNode* head, int left, int right){

    if(right == left) return head;
    struct ListNode* stack[MAX];
    struct ListNode* dummy = (struct ListNode*)calloc(1, sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* temp = dummy;
    struct ListNode* start = head;
    int n = right - left + 1;
    
    while(left - 1 > 0) {
        temp = temp->next;
        start = start->next;
        left--;
    }

    for(int i = 0; i < n; i++) {
        stack[i] = start;
        start = start->next;
    }

    for(int i = n - 1; i >= 0; i--) {
        temp->next = stack[i];
        temp = temp->next;
    }  

    temp->next = start; 

    return dummy->next;
}
