class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<vector<int>> dp(rows, vector<int>(cols, -1)); // Memoization table
        int totalCount = 0;

        // Call the helper function for each cell and accumulate the count
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                totalCount += countSquaresHelper(matrix, dp, i, j);
            }
        }

        return totalCount;
    }

private:
    int countSquaresHelper(vector<vector<int>>& matrix, vector<vector<int>>& dp, int i, int j) {
        // Base cases
        if (i < 0 || j < 0) return 0; // Out of bounds
        if (matrix[i][j] == 0) return 0; // If cell is 0, no square can end here

        // If already computed, return the stored result
        if (dp[i][j] != -1) return dp[i][j];

        // Recursively calculate the size of the largest square ending at (i, j)
        dp[i][j] = 1 + min({
            countSquaresHelper(matrix, dp, i - 1, j),       // Top
            countSquaresHelper(matrix, dp, i, j - 1),       // Left
            countSquaresHelper(matrix, dp, i - 1, j - 1)    // Top-left diagonal
        });

        return dp[i][j];
    }
};
