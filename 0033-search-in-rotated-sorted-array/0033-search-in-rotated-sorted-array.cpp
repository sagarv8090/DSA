class Solution {
public:
   int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;  // Handle the case of an empty array.

        int start = 0;
        int end = n - 1;

        while (start <= end) {
            int mid = start + (end - start) / 2;

            if (nums[mid] == target) return mid;

            // Check which side of the array is sorted and perform a binary search there.
            if (nums[start] <= nums[mid]) {  // Left side is sorted.
                if (target >= nums[start] && target < nums[mid])
                    end = mid - 1;
                else
                    start = mid + 1;
            } else {  // Right side is sorted.
                if (target > nums[mid] && target <= nums[end])
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }

        return -1;  // Target element not found.
    }
};