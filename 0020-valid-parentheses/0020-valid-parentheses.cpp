class Solution {
public:
    bool isValid(string s) {
    stack<char>st;
    int n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]=='(' or s[i]=='{' or s[i]=='['){
            st.push(s[i]);
        }
        else{
            if(st.empty() or (st.top()=='(' && s[i]!=')') || st.empty() or (st.top()=='{' && s[i]!='}') || st.empty() or (st.top()=='[' && s[i]!=']')) 
            
                return false;
            
            else 
                st.pop();
            
        }

    }
    return st.empty();
    }
};