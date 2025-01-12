class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                st.push(s[i]);
            }
            else if(!st.empty()){
                if((st.top()=='(' && s[i]==')') || (st.top()=='{' && s[i]=='}') || (st.top()=='[' && s[i]==']')){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                if(st.empty() && s[i]==')' || s[i]=='}' || s[i]==']'){
                    return false;
                }
            }
        }
        return st.empty();
    }
};