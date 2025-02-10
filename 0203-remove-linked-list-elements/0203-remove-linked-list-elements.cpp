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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode*current=head;
        ListNode*previous=NULL;
        if(head==NULL){
            return head;
        }
        while(head!=NULL && head->val==val){
            head=head->next;
        }

        while(current!=NULL && current->next!=NULL){

        if(current->next->val==val){
            previous=current;

            previous->next=current->next->next;
      
        }
        else{
            previous=current;
            current=current->next;

        }
        }
        return head;
        
    }
};
