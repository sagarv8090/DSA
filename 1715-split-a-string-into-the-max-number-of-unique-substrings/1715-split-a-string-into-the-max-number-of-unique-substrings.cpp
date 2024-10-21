class Solution {
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> st; // To keep track of unique substrings
        return backtrack(s, 0, st); // Start backtracking from index 0
    }

private:
    int backtrack(const string& s, int start, unordered_set<string>& st) {
        if (start == s.size()) {
            return 0; // Base case: if we've reached the end of the string
        }
        
        int maxSplits = 0;
        string current = "";
        
        // Try all possible substrings starting at `start`
        for (int i = start; i < s.size(); ++i) {
            current += s[i];
            
            if (st.find(current) == st.end()) { // If the substring is unique
                st.insert(current); // Add to the set of unique substrings
                maxSplits = max(maxSplits, 1 + backtrack(s, i + 1, st)); // Recur for the rest of the string
                st.erase(current); // Backtrack and remove the current substring
            }
        }
        
        return maxSplits;
    }
};
