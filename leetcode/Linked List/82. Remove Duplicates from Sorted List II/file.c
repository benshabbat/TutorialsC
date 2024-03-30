/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head) {
    // Edge case: empty list or single node
    if (!head || !head->next) {
        return head;
    }
    
    struct ListNode dummy;
    dummy.next = head;
    struct ListNode* prev = &dummy;
    struct ListNode* current = head;
    
    while (current) {
        // Skip duplicates
        while (current->next && current->val == current->next->val) {
            current = current->next;
        }
        
        // If no duplicates, move prev and current
        if (prev->next == current) {
            prev = prev->next;
        } else { // If duplicates, skip them
            prev->next = current->next;
        }
        
        current = current->next;
    }
    
    return dummy.next;
}