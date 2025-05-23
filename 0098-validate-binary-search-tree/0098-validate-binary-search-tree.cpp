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
public:
    bool isValidBST(TreeNode* root) {
        // Call the helper function with initial range set to negative and positive infinity
        return bst(root, LLONG_MIN, LLONG_MAX);
    }

    // Helper function to perform DFS traversal
    bool bst(TreeNode* root, long long min_val, long long max_val) {
        // Base case: If the current node is NULL, return true
        if (root == NULL) {
            return true;
        }

        // Check if the current node's value is within the valid range
        if (!(min_val < root->val && root->val < max_val)) {
            return false;
        }

        // Recursively check the left and right subtrees with updated ranges
        return bst(root->left, min_val, root->val) && bst(root->right, root->val, max_val);
    }
};