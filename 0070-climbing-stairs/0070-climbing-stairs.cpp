class Solution {
int fib(int n,vector<int>&dp){
     if(n==0)return 1;
     if(n==1)return 1;
     if(dp[n]!=-1)return dp[n];

     int left=fib(n-1,dp);
     int right=0;
     if(n>1){
         right=fib(n-2,dp);
     }
     return dp[n]=left+right;
}
public:
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
       return fib(n,dp);
    }
};
