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
    bool checkSum(TreeNode* root,int targetSum,int sum){
        if(root==NULL)return false;
        if(root->left==NULL && root->right==NULL){
            sum+=root->val;
            return sum==targetSum;
        }
        sum+=root->val;
        bool left=checkSum(root->left,targetSum,sum);
        bool right=checkSum(root->right,targetSum,sum);

        return left || right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return checkSum(root,targetSum,0);
    }
};