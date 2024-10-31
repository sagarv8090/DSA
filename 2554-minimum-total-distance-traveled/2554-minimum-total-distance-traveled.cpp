class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        // Sort robots and factories by their positions
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());

        int n = robot.size();
        int m = factory.size();

        // Initialize dp array with high values
        vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, LLONG_MAX));
        dp[0][0] = 0;

        // Fill DP table
        for (int j = 1; j <= m; ++j) {
            dp[0][j] = 0; // No robots to repair, cost is zero
            for (int i = 1; i <= n; ++i) {
                dp[i][j] = dp[i][j - 1]; // Skip current factory
                long long cost = 0;

                // Try to assign up to limit
                int limit = factory[j - 1][1];
                int position_j = factory[j - 1][0];

                for (int k = 1; k <= limit && k <= i; ++k) {
                    cost += abs(robot[i - k] - position_j);
                    if (dp[i - k][j - 1] != LLONG_MAX) {
                        dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + cost);
                    }
                }
            }
        }
        
        return dp[n][m];
    }
};
