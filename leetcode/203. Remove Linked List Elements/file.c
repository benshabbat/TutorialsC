/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode *prev = NULL;
    struct ListNode *curr = head;

    while (curr != NULL) {
        if (curr->val == val) {
            if (prev == NULL) {
                // If the first node matches val, move head to the next node
                head = curr->next;
                free(curr);
                curr = head;
            } else {
                // Remove the current node by linking the previous node to the next node
                prev->next = curr->next;
                free(curr);
                curr = prev->next;
            }
        } else {
            // Move to the next node
            prev = curr;
            curr = curr->next;
        }
    }

    return head;
}