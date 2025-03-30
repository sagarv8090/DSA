class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        int i = 0;
        int ans = 0;
        int sign = 1;

        // Skip leading whitespace
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Handle sign
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        // Convert digits to integer
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            int digit = s[i] - '0';
            
            // Check for overflow and underflow
            if (ans > (INT_MAX - digit) / 10) {
                return (sign == 1) ? INT_MAX : INT_MIN;
            }
            
            ans = ans * 10 + digit;
            i++;
        }

        return ans * sign;
    }
};
