class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> delta(n + 1, 0); // Array to record net shifts

        // Update delta based on shift operations
        for (auto& it : shifts) {
            int start = it[0];
            int end = it[1];
            int direction = it[2];
            delta[start] += (direction == 1) ? 1 : -1;
            if (end + 1 < n) {
                delta[end + 1] -= (direction == 1) ? 1 : -1;
            }
        }

        // Compute prefix sum of delta and apply shifts
        int shift = 0;
        for (int i = 0; i < n; ++i) {
            shift += delta[i];
            // Normalize shift to handle cyclic behavior of alphabet
            int netShift = (shift % 26 + 26) % 26; 
            s[i] = 'a' + (s[i] - 'a' + netShift) % 26;
        }

        return s;
    }
};
