/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode dummyHead;
    struct ListNode *current = &dummyHead;
    int carry = 0;

    while (l1 != NULL || l2 != NULL || carry) {
        int sum = carry + (l1 ? l1->val : 0) + (l2 ? l2->val : 0);
        carry = sum / 10;
        
        current->next = malloc(sizeof(struct ListNode));
        current = current->next;
        current->val = sum % 10;
        current->next = NULL;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }

    return dummyHead.next;
}