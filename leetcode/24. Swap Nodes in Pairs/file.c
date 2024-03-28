/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* swapPairs(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode* dummy = malloc(sizeof(struct ListNode));
    dummy->next = head;
    struct ListNode* prev = dummy;
    struct ListNode* first = head;
    struct ListNode* second = head->next;

    while (first != NULL && second != NULL) {
        prev->next = second;
        first->next = second->next;
        second->next = first;

        prev = first;
        first = first->next;
        if (first != NULL) {
            second = first->next;
        }
    }

    head = dummy->next;
    free(dummy);
    return head;
}