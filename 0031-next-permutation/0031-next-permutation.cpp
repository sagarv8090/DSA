class Solution {
private:
    // Helper function to reverse a range of elements in the vector
    void reverseRange(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }

public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find the first decreasing element from the right
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: Find the first element greater than the decreasing element
            int j = n - 1;
            while (j > i && nums[j] <= nums[i]) {
                j--;
            }

            // Step 3: Swap the decreasing element with the next greater element
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse the remaining elements to get the next permutation
        reverseRange(nums, i + 1, n - 1);
    }
};