/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return true;
    }
    
    // Find the middle of the linked list
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    while (fast->next != NULL && fast->next->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    // Reverse the second half of the linked list
    struct ListNode* prev = NULL;
    struct ListNode* current = slow->next;
    while (current != NULL) {
        struct ListNode* next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    // Compare the first half with the reversed second half
    struct ListNode* p1 = head;
    struct ListNode* p2 = prev;
    while (p2 != NULL) {
        if (p1->val != p2->val) {
            return false;
        }
        p1 = p1->next;
        p2 = p2->next;
    }
    
    return true;
}
