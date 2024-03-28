/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* partition(struct ListNode* head, int x) {
    struct ListNode less_head, greater_head;
    struct ListNode *less_ptr = &less_head, *greater_ptr = &greater_head;
    
    while (head != NULL) {
        if (head->val < x) {
            less_ptr->next = head;
            less_ptr = less_ptr->next;
        } else {
            greater_ptr->next = head;
            greater_ptr = greater_ptr->next;
        }
        head = head->next;
    }
    
    greater_ptr->next = NULL; // Set the end of the greater list to NULL
    less_ptr->next = greater_head.next; // Connect the two lists
    
    return less_head.next; // Return the head of the merged list
}