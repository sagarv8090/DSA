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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* current=head;
    
        ListNode* previous=NULL;
        if(current==NULL || current->next==NULL){
            return head;
        }
        while(current->next!=NULL){
                ListNode* forward=current->next;
             if(current->val==forward->val){
                 previous=current;
                 forward=forward->next;
                 current->next=NULL;
                 previous->next=forward;
             }
             else{

current=forward;
previous=forward;
forward=forward->next;
             }
             
        }
        return head;
        
    }
};