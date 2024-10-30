#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Calculate LIS ending at each index
        vector<int> lis(n, 1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (nums[i] > nums[j]) {
                    lis[i] = max(lis[i], lis[j] + 1);
                }
            }
        }

        // Step 2: Calculate LDS starting at each index
        vector<int> lds(n, 1);
        for (int i = n - 1; i >= 0; --i) {
            for (int j = n - 1; j > i; --j) {
                if (nums[i] > nums[j]) {
                    lds[i] = max(lds[i], lds[j] + 1);
                }
            }
        }

        // Step 3: Calculate minimum removals for valid peaks
        int minRemovals = n;
        for (int i = 1; i < n - 1; ++i) {
            if (lis[i] > 1 && lds[i] > 1) {  // valid peak
                minRemovals = min(minRemovals, n - (lis[i] + lds[i] - 1));
            }
        }

        return minRemovals;
    }
};
