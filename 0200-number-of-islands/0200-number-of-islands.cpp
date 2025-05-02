class Solution {
    private:
    void bfs(int row,int col,vector<vector<bool>>&vis,vector<vector<char>>&grid){
        int n=grid.size();
        int m=grid[0].size();
        vis[row][col]=true;
        queue<pair<int,int>>q;
        q.push({row,col});
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        while(!q.empty()){
            int row=q.front().first;
            int col=q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow=row+delrow[i];
                int ncol=col+delcol[i];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                    vis[nrow][ncol]=true;
                    q.push({nrow,ncol});
                }
            }

        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<bool>>vis(n,vector<bool>(m,false));
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    cnt++;
                    bfs(i,j,vis,grid);
                }
            }
        }
        return cnt;
    }
};
