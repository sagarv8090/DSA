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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* newList=new ListNode();
        ListNode* dummy=newList;
        int carry=0;
        while(l1 || l2 || carry){
            int value=0;
            if(l1!=NULL){
                value+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
            value+=l2->val;
            l2=l2->next;
            }
            value+=carry;
            int rem=value%10;
            carry=value/10;
            ListNode* node=new ListNode(rem);
            newList->next=node;
            newList=newList->next;
        }
        return dummy->next;
    }
};