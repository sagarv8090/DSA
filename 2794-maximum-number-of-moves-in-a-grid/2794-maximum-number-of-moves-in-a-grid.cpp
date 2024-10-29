class Solution {
private:
    bool isValid(int row, int col, int n, int m) {
        return row >= 0 && row < n && col >= 0 && col < m;
    }
    
    int dfs(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& memo, int n, int m) {
        if (memo[row][col] != -1) {
            return memo[row][col];
        }

        int maxMovesFromHere = 0;
        vector<pair<int, int>> directions = {{-1, 1}, {0, 1}, {1, 1}}; // right-up, right, right-down
        
        for (auto [dr, dc] : directions) {
            int newRow = row + dr;
            int newCol = col + dc;
            
            if (isValid(newRow, newCol, n, m) && grid[newRow][newCol] > grid[row][col]) {
                maxMovesFromHere = max(maxMovesFromHere, 1 + dfs(newRow, newCol, grid, memo, n, m));
            }
        }
        
        return memo[row][col] = maxMovesFromHere;
    }
    
public:
    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int maxMoves = 0;
        
        vector<vector<int>> memo(n, vector<int>(m, -1)); // Memoization to avoid redundant calculations

        for (int i = 0; i < n; i++) {
            maxMoves = max(maxMoves, dfs(i, 0, grid, memo, n, m));
        }
        
        return maxMoves;
    }
};
