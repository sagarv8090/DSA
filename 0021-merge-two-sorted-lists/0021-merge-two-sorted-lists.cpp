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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* current=dummy;
        if(l1==NULL)return l2;
        if(l2==NULL)return l1;
        while(l1!=NULL && l2!=NULL){
            if(l1->val<=l2->val){
                current->next=l1;
                l1=l1->next;
            }
            else{
                current->next=l2;
                l2=l2->next;
                
            }
            current=current->next;
        }
        if(l1==NULL){
            current->next=l2;
        }
        else{
            current->next=l1;
        }
        return dummy->next;
    }
};