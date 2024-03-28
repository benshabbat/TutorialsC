/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    struct ListNode* prev = NULL;

    // Move fast pointer n steps ahead
    for (int i = 0; i < n; i++) {
        if (fast == NULL) return NULL; // Invalid input, n is greater than the length of the list
        fast = fast->next;
    }

    // Move fast to the end of the list and slow will be at the node to remove
    while (fast != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next;
    }

    // Remove the nth node from the end
    if (prev == NULL) {
        head = head->next;
    } else {
        prev->next = slow->next;
    }

    free(slow);

    return head;
}