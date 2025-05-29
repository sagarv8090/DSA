class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less_head = new ListNode(0); // Dummy node for less than x
        ListNode* greater_head = new ListNode(0); // Dummy node for greater than or equal to x
        ListNode* less_ptr = less_head;
        ListNode* greater_ptr = greater_head;
        
        ListNode* current = head;
        
        while (current != nullptr) {
            if (current->val < x) {
                less_ptr->next = current;
                less_ptr = less_ptr->next;
            } else {
                greater_ptr->next = current;
                greater_ptr = greater_ptr->next;
            }
            current = current->next;
        }
        
        // Connect the two partitions
        less_ptr->next = greater_head->next;
        greater_ptr->next = nullptr; // Ensure the end of the list
        
        // Return the head of the partitioned list
        return less_head->next;
    }
};