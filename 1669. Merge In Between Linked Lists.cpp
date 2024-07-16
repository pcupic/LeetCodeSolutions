/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeInBetween(struct ListNode* list1, int a, int b, struct ListNode* list2){

    struct ListNode* head2 = list2;
    struct ListNode* tail = NULL;
    while(list2) {
        tail = list2;
        list2 = list2->next;
    }

    int i = 0;
    struct ListNode* ans = list1;
    struct ListNode* temp;
    while(list1) {
        if(i + 1 == a) {
            temp = list1->next;
            list1->next = head2;
            list1 = temp;
        }
        else if(i == b) {
            tail->next = list1->next;
            break;
        }
        else {
            list1 = list1->next;
        }
        i++;
    }

    return ans;
}
