#include <vector>
#include <climits>
using namespace std;

class Solution {
private:
    int solve(int ind, vector<int>& nums, int n, vector<int>& dp) {
        if (ind >= n - 1) return 0; // no more jumps needed if we reach or exceed the last index
        if (dp[ind] != -1) return dp[ind]; // use memoized result if available

        int mini = INT_MAX;
        for (int i = 1; i <= nums[ind]; ++i) {
            if (ind + i < n) {
                int jumps = solve(ind + i, nums, n, dp);
                if (jumps != INT_MAX) {
                    mini = min(mini, jumps + 1);
                }
            }
        }
        return dp[ind] = mini;
    }

public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return solve(0, nums, n, dp);
    }
};
