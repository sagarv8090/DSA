class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int row = mat.size(), col = mat[0].size();
        vector<vector<int>> dist(row, vector<int>(col, -1));
        queue<pair<int, int>> q;

        // Step 1: Push all 0s into queue and mark their distance as 0
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (mat[i][j] == 0) {
                    dist[i][j] = 0;
                    q.push({i, j});
                }
            }
        }

        // Step 2: BFS from all 0s
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();

            for (int k = 0; k < 4; ++k) {
                int ni = i + delRow[k];
                int nj = j + delCol[k];

                if (ni >= 0 && nj >= 0 && ni < row && nj < col && dist[ni][nj] == -1) {
                    dist[ni][nj] = dist[i][j] + 1;
                    q.push({ni, nj});
                }
            }
        }

        return dist;
    }
};
