class Solution {
public:
    int strStr(string haystack, string needle) {
        map<int,char>mp;
        int n=haystack.size();
        char ch=needle[0];
        for(int i=0;i<n;i++){
            if(haystack[i]==ch){
                mp[i]=ch;
            }
        }
        for(auto it:mp){
            int i=it.first;
            int m=needle.size();
            string str=haystack.substr(i,m);
            if(needle==str){
                return i;
            }
        }
        return -1;
    }
};