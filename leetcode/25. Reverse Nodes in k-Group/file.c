/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
 struct ListNode* reverseList(struct ListNode* head, int k) {
    struct ListNode *prev = NULL, *curr = head, *next = NULL;
    while (k-- > 0) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

struct ListNode* reverseKGroup(struct ListNode* head, int k) {
    if (!head || k == 1) return head; // No need to reverse

    struct ListNode dummy; // Dummy node to handle the edge case of reversing from the beginning
    dummy.next = head;
    struct ListNode *prev = &dummy, *curr = head;

    while (curr) {
        int count = 0;
        struct ListNode *start = curr;
        while (curr && count < k) {
            curr = curr->next;
            count++;
        }

        if (count == k) {
            struct ListNode *newHead = reverseList(start, k); // Reverse the sublist
            prev->next = newHead;
            prev = start; // Move prev to the end of the reversed sublist
        } else {
            prev->next = start; // If the remaining sublist is less than k, append it as is
        }
    }

    return dummy.next;
}

