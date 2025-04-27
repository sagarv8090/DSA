class Solution {
    private:
    void f(int row,int col,vector<vector<char>>& board, vector<vector<int>>&vis,int m,int n){
        vis[row][col]=1;

        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int newrow=row+delrow[i];
            int newcol=col+delcol[i];
            if(newrow>=0 && newrow<m && newcol>=0 && newcol<n && !vis[newrow][newcol] && board[newrow][newcol]=='O'){
                f(newrow ,newcol,board,vis,m,n);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m=board.size();
        int n=board[0].size();
        vector<vector<int>>vis(m, vector<int>(n,0));
        //traversing first row
        for(int j=0;j<n;j++){
            if(!vis[0][j] && board[0][j]=='O'){
                f(0,j,board,vis,m,n);
            }
        }
        //traversing last col
        for(int i=0;i<m;i++){
                if(!vis[i][n-1] && board[i][n-1]=='O'){
                f(i,n-1,board,vis,m,n);
            }
        }
        //traversing last row
        for(int j=0;j<n;j++){
                if(!vis[m-1][j] && board[m-1][j]=='O'){
                f(m-1,j,board,vis,m,n);
        }
        }
        //traversing first col
        for(int i=0;i<m;i++){
                if(!vis[i][0]&& board[i][0]=='O'){
                    f(i,0,board,vis,m,n);
                }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && board[i][j]=='O'){
                    board[i][j]='X';
                }
            }
        }
    }
};