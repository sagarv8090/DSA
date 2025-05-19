class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxi=0;
        int left=0;
        unordered_map<char,int>m;
        for(int i=0;i<n;i++){
            int current=s[i];
            if(m.find(current)!=m.end()){
                left=max(left,m[current]+1);
            }
            m[current]=i;
            maxi=max(maxi,i-left+1);
        }
        return maxi;
    }
};