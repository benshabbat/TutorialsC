/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteMiddle(struct ListNode* head) {
    if (head == NULL|| head->next == NULL) {
        return NULL;
    }
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    struct ListNode *prevMiddle = slow;
    while (fast != NULL && fast->next != NULL)
    {
        prevMiddle=slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prevMiddle->next=slow->next;
    free(slow);
    
    return head;
}