/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

// Helper function to reverse a linked list
struct ListNode* reverseList(struct ListNode* head) {
    struct ListNode* prev = NULL;
    struct ListNode* current = head;
    struct ListNode* next = NULL;
    
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

// Helper function to find the middle of a linked list
struct ListNode* findMiddle(struct ListNode* head) {
    struct ListNode* slow = head;
    struct ListNode* fast = head;
    
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    return slow;
}

void reorderList(struct ListNode* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }
    
    // Find the middle of the list
    struct ListNode* middle = findMiddle(head);
    // Reverse the second half of the list
    struct ListNode* secondHalf = reverseList(middle->next);
    middle->next = NULL; // Break the list into two parts
    
    // Merge the first half and the reversed second half
    struct ListNode* current = head;
    struct ListNode* temp = NULL;
    while (secondHalf != NULL) {
        temp = current->next;
        current->next = secondHalf;
        secondHalf = secondHalf->next;
        current->next->next = temp;
        current = temp;
    }
}