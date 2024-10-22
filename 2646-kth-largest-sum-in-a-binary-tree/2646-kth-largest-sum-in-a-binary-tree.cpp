class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        if (!root) return -1; // Check for null root edge case
        queue<TreeNode*> q;
        q.push(root);
        vector<long long> temp;

        while (!q.empty()) {
            int length = q.size();
            long long sum = 0;

            for (int i = 0; i < length; i++) {
                TreeNode* node = q.front();
                q.pop();
                sum += node->val;

                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
            }

            temp.push_back(sum);  // Add the sum of this level to the list
        }

        if (k > temp.size()) return -1;  // Handle out-of-bounds case for k

        sort(temp.rbegin(), temp.rend());  // Sort in descending order
        return temp[k-1];  // Return the kth largest element
    }
};
