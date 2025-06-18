class Solution {
public:
    int longestPalindrome(string s) {
        int length=0;
        unordered_map<char,int>mp;
        bool flag=false;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        for(auto it:mp){
            if(it.second%2==0){
                length+=it.second;
            }
            else{
                flag=true;
                if(it.second>1){
                    length+=it.second-1;
                }
            }
        }
        if(flag){
            length++;
        }
        return length;
    }
};