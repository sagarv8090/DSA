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
        ListNode* ans=NULL;
        ListNode* prev=NULL;
        int carry=0;
        while(l1!=NULL || l2!=NULL){
            int value=carry;
            if(l1!=NULL){
                value+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL){
                value+=l2->val;
                l2=l2->next;
            }
            int rem=value%10;
             carry=value/10;
            ListNode* current=new ListNode(rem);
            if(ans==NULL){
                ans=current;
                prev=current;
            }
            else{
                prev->next=current;
                prev=current;
            }

        }
        if(carry>0){
            ListNode* current=new ListNode(carry);
                prev->next=current;
            }
        
        return ans;
    }
};