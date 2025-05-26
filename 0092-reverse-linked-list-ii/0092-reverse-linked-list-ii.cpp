/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (head == NULL || head->next == NULL || left == right) return head;
        int cnt = 1;
        ListNode* temp = head;
        ListNode* previous = NULL;
        while (cnt < left) {
            previous = temp;
            temp = temp->next;
            cnt++;
        }
        ListNode* current = temp;
        ListNode* forward = NULL;
        ListNode* newhead = NULL;
        while (cnt <= right) {
            forward = current->next;
            current->next = newhead;
            newhead = current;
            current = forward;
            cnt++;
        }
        if (previous != NULL) {
            previous->next = newhead;
        } else {
            head = newhead;
        }
        temp->next = current;
        return head;
    }
};


