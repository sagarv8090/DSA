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
    ListNode* sortList(ListNode* head) {
            vector<int>v;
    ListNode* temp=head;
    while(temp!=NULL){
        v.push_back(temp->val);
        temp=temp->next;
    }
    sort(v.begin(),v.end());
    ListNode* previous=NULL;
    ListNode* ans=NULL;
    for(int i=0;i<v.size();i++){
        ListNode* current=new ListNode(v[i]);
        if(previous==NULL){
            ans=current;
            previous=current;
        }
        else{
            previous->next=current;
            previous=current;
        }

    }
    return ans;
    }
};