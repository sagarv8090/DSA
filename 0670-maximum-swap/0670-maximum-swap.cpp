class Solution {
public:
    int maximumSwap(int num) {
        vector<int> v;
        
        // Step 1: Convert the number into a vector of digits
        while (num > 0) {
            int digit = num % 10;
            v.push_back(digit);
            num = num / 10;
        }
        
        reverse(v.begin(), v.end());  // Get digits in correct order
        int n = v.size();
        
        // Step 2: Find the last occurrence of each digit (0-9)
        vector<int> last(10, -1);  // To store the last index of each digit
        for (int i = 0; i < n; i++) {
            last[v[i]] = i;
        }
        
        // Step 3: Traverse the digits to find the first opportunity to swap
        for (int i = 0; i < n; i++) {
            // Look for a larger digit in the remaining part of the number
            for (int d = 9; d > v[i]; d--) {
                if (last[d] > i) {
                    // Swap the current digit with the last occurrence of the larger digit
                    swap(v[i], v[last[d]]);
                    // Return the result after the swap
                    long long ans = 0;
                    for (int j = 0; j < n; j++) {
                        ans = ans * 10 + v[j];
                    }
                    return ans;
                }
            }
        }
        
        // If no swap was made, return the original number
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            ans = ans * 10 + v[i];
        }
        return ans;
    }
};
