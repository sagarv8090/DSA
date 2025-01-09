class Solution {
public:
    bool isPalindrome(int x) {
        vector<int>v;
        while(x>0){
            int rem=x%10;
            v.push_back(rem);
            int digit=x/10;
            x=digit;

        }
        int i=0;
        int j=v.size();
        if(x<0){
            return false;
        }
        else{
while(i<j){
if(v[i]!=v[j-1]){
    return false;
}
else{
    i++;
    j--;
}
}
return true;
        
    }
        }

};