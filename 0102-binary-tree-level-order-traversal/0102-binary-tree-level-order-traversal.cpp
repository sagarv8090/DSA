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
class Solution
{
public:
    void levelordertraversal(TreeNode *root, vector<vector<int>> &v)
    {
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *temp;
        int length;
        while (!q.empty())
        {
            vector<int> x;
            length = q.size();
            for (int i = 0; i < length; i++)
            {
                temp = q.front();
                q.pop();
                x.push_back(temp->val);
                if (temp->left)
                    q.push(temp->left);
                if (temp->right)
                    q.push(temp->right);
            }
            v.push_back(x);
        }
    }

    vector<vector<int>> levelOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return {};
        }
        vector<vector<int>> v;
        levelordertraversal(root, v);
        return v;
    }
};


