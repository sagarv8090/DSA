/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:

pair<bool,int>isbalancedfast(TreeNode* root){
    pair<bool,int>p=make_pair(true,0);
if(root==NULL){
    return p;
}
pair<bool,int>left=isbalancedfast(root->left);
pair<bool,int>right=isbalancedfast(root->right);

bool leftans=left.first;
bool rightans=right.first;

bool diff=abs(left.second-right.second)<=1;

pair<bool,int>ans;
ans.second=max(left.second,right.second)+1;
if(leftans && rightans && diff){
    
     ans.first=true;
}
else{
    ans.first=false;
}
return ans;
}



public:

    bool isBalanced(TreeNode* root) {
        return isbalancedfast(root).first;
    }
};