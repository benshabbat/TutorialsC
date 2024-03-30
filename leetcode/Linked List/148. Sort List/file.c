/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* merge(struct ListNode* left, struct ListNode* right) {
    struct ListNode dummy;
    struct ListNode* tail = &dummy;

    while (left && right) {
        if (left->val < right->val) {
            tail->next = left;
            left = left->next;
        } else {
            tail->next = right;
            right = right->next;
        }
        tail = tail->next;
    }

    tail->next = left ? left : right;
    return dummy.next;
}

struct ListNode* mergeSort(struct ListNode* head) {
    if (!head || !head->next) {
        return head;
    }

    struct ListNode* slow = head;
    struct ListNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }

    struct ListNode* right = slow->next;
    slow->next = NULL;

    struct ListNode* leftSorted = mergeSort(head);
    struct ListNode* rightSorted = mergeSort(right);

    return merge(leftSorted, rightSorted);
}

struct ListNode* sortList(struct ListNode* head) {
    return mergeSort(head);
}