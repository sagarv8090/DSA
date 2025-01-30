class Solution {
    public int[] twoSum(int[] nums, int target) {
        Map<Integer, Integer> mp = new HashMap<>();
        
        for (int i = 0; i < nums.length; i++) {
            int targetEle = target - nums[i];
            if (mp.containsKey(targetEle) && mp.get(targetEle) != i) {
                return new int[]{i, mp.get(targetEle)};
            }
            mp.put(nums[i], i);
        }
        
        return new int[]{-1, -1}; // No solution case
    }
}
