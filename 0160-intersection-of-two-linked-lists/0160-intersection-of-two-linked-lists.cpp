/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        
        // Traverse both lists until they meet or reach the end
        while (a != b) {
            a = (a != NULL) ? a->next : headB; // Move a to the next node or to headB if it reaches the end
            b = (b != NULL) ? b->next : headA; // Move b to the next node or to headA if it reaches the end
        }
        
        // Either a or b will be the intersection point or nullptr if there's no intersection
        return b;
    }
};