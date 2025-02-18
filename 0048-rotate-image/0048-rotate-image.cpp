class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>> mat(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m; j++){
                int x=matrix[i][j];
                mat[j][m-i-1]=x;
                 
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                matrix[i][j]=mat[i][j];
            }
        }
    }
};