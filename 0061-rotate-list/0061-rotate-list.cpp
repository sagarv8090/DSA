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
    private:
    int getlength(ListNode* head){
        ListNode* temp=head;
        int length=0;
        while(temp!=NULL){
            temp=temp->next;
            length++;
        }
        return length;
    }
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || k==0)return head;
        int length=getlength(head);
        k=k%length;
        if(k==0)return head;

        ListNode* current=head;
        int cnt=1;
        while(cnt<length-k){
            current=current->next;
            cnt++;
        }
        ListNode* newhead=current->next;
        current->next=NULL;
        ListNode* temp=newhead;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=head;
        return newhead;
    }
};
