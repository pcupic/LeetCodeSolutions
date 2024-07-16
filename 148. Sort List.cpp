/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

void splitList(struct ListNode* head, struct ListNode** front, struct ListNode** back) {
    struct ListNode* slow;
    struct ListNode* fast;

    if (head == NULL || head->next == NULL) {
        *front = head;
        *back = NULL;
    } else {
        slow = head;
        fast = head->next;

        while (fast != NULL) {
            fast = fast->next;
            if (fast != NULL) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        *front = head;
        *back = slow->next;
        slow->next = NULL;
    }
}

struct ListNode* mergeLists(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->val < l2->val) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

    if (l1 != NULL) {
        tail->next = l1;
    } else {
        tail->next = l2;
    }

    return dummy.next;
}

struct ListNode* mergeSort(struct ListNode* head) {
    struct ListNode* front;
    struct ListNode* back;

    if (head == NULL || head->next == NULL) {
        return head;
    }

    splitList(head, &front, &back);

    front = mergeSort(front);
    back = mergeSort(back);

    return mergeLists(front, back);
}

struct ListNode* sortList(struct ListNode* head) {
    return mergeSort(head);
}
