/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* createNode(int val) {
    struct ListNode *newNode = (struct ListNode*)malloc(sizeof(struct ListNode));
    newNode->val = val;
    newNode->next = NULL;
    return newNode;
}

struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;
    struct ListNode *next;
    
    while (curr != NULL) {
        next = curr->next;  
        curr->next = prev;  
        prev = curr;        
        curr = next;        
    }
    return prev;  
}

struct ListNode* doubleIt(struct ListNode* head) {
    head = reverseList(head);
    
    struct ListNode *curr = head;
    struct ListNode *last = NULL;  
    int carry = 0;
    
    while (curr != NULL) {
        int value = curr->val * 2 + carry;
        curr->val = value % 10; 
        carry = value / 10;      
        
        last = curr;            
        curr = curr->next;      
    }
    
    if (carry > 0) {
        last->next = createNode(carry);
    }
    
    return reverseList(head);
}
