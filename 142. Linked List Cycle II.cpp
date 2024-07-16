/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
    
    struct ListNode *slow = head;
    struct ListNode *fast = head;
    int cycleDetected = 0;
    while(fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) {
            cycleDetected = 1;
            break;
        }
    }

    if(!cycleDetected) return NULL;
    	
    fast = head;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}
