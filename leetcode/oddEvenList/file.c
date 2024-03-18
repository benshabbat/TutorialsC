/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* oddEvenList(struct ListNode* head) {
    if (head == NULL || head->next == NULL)
    {
        return head; // If the list is empty or has only one node, no need to rearrange
    }

    struct ListNode *odd = head;
    struct ListNode *even = head->next;
    struct ListNode *evenStart = even; // Save the start of even list

    while (even != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }

    odd->next = evenStart; // Connect the odd list to the even list

    return head;
}