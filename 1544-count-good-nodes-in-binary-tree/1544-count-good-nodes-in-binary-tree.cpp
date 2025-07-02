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
    void dfs(TreeNode* root, int& ans, int maxi){
        if(root==nullptr)return;
        if(root->val>=maxi){
            ans++;
            maxi=max(maxi,root->val);
        }
        dfs(root->left,ans,maxi);
        dfs(root->right,ans,maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        if(root==nullptr)return 0;
        int maxi=root->val;
        int ans=0;
        dfs(root,ans,maxi);
        return ans;

    }
};