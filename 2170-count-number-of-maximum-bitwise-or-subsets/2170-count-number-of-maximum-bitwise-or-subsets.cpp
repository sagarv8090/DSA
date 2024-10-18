class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOr = 0, count = 0;

        // Step 1: Calculate the maximum possible bitwise OR
        for (int num : nums) {
            maxOr |= num;
        }

        // Step 2: Backtrack to find all subsets and count those that match maxOr
        backtrack(nums, 0, 0, maxOr, count);
        
        return count;
    }

private:
    // Backtracking function to explore all subsets
    void backtrack(vector<int>& nums, int index, int currentOr, int maxOr, int& count) {
        if (index == nums.size()) {
            if (currentOr == maxOr) {
                count++;
            }
            return;
        }
        
        // Option 1: Include the current number in the subset
        backtrack(nums, index + 1, currentOr | nums[index], maxOr, count);
        
        // Option 2: Exclude the current number from the subset
        backtrack(nums, index + 1, currentOr, maxOr, count);
    }
};
