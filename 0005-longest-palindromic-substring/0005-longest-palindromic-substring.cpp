class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,false));
        int start=0;
        int maxlen=1;
        //substring of size 1 is palindrome
        for(int i=0;i<=n;i++){
            dp[i][i]=true;
        }

        //substring of size 2 checking palindrome
        for(int i=0;i<n-1;i++){
            if(s[i]==s[i+1]){
                start=i;
                maxlen=2;
                dp[i][i+1]=true;
            }
        }

        //substring of size greater or equal to 3
        for(int len=3;len<=n;len++){
            for(int i=0;i<n-len+1;i++){
                int end=i+len-1;
                if(s[i]==s[end] && dp[i+1][end-1]){
                    dp[i][end]=true;
                    if(len>maxlen){
                        maxlen=len;
                        start=i;
                    }
                }
            }
        }
        return s.substr(start,maxlen);
    }
};