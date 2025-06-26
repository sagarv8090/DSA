class Solution {
    void dfs(TreeNode* node, int depth, int& maxDepth, int& leftVal) {
        if (!node) return;
        
        // When a new maximum depth is found, update leftVal
        if (depth > maxDepth) {
            maxDepth = depth;
            leftVal = node->val;
        }
        
        // Always visit left child before right
        dfs(node->left, depth + 1, maxDepth, leftVal);
        dfs(node->right, depth + 1, maxDepth, leftVal);
    }

public:
    int findBottomLeftValue(TreeNode* root) {
        int maxDepth = -1;
        int leftVal = root->val;
        dfs(root, 0, maxDepth, leftVal);
        return leftVal;
    }
};
