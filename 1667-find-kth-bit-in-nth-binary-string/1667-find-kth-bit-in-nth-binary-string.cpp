class Solution {
    private:
    void invert(string& temp){
        int n=temp.size();
        for(int i=0;i<n;i++){
            if(temp[i]=='0'){
                temp[i]='1';
            }
            else{
                temp[i]='0';
            }
        }
    }

public:
    char findKthBit(int n, int k) {
        string s="0";
        char ch;
        for(int i=1;i<n;i++){
            string temp=s;
            s+='1';
            invert(temp);
            reverse(temp.begin(),temp.end());
            s=s+temp;
        }
        return s[k-1];
    }
};