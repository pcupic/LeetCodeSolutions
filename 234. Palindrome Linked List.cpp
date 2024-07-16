/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

bool isPalindrome(struct ListNode* head){

    struct ListNode* temp = head;
    int n = 0;
    while(temp) {
        temp = temp->next;
        n++;
    }

    int* arr = (int*)calloc(n, sizeof(int));
    int i = 0;  
    temp = head;
    while(i < n && temp) {
        arr[i++] = temp->val;
        temp = temp->next;
    }

    for(i = 0; i < n / 2; i++) {
        if(arr[i] != arr[n - 1 - i]) {
            return false;
        }
    }

    return true;
}


