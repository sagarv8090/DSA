class Solution {
public:
    bool isSubsequence(string s, string t) {
        int cnt=s.size();
        int temp=0;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            for(int j=temp;j<t.size();j++){
                if(ch==t[j]){
                    cnt--;
                    temp=j+1;
                    break;
                }
            }
        }
        if(cnt==0){
            return true;
        }
        return false;
    }
};