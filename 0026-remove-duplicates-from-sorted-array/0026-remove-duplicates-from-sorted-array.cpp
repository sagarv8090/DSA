class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int cnt=1;
        int n=nums.size();
        if(n==0)return 0;
        for(int i=1;i<n;i++){
            if(nums[i]!=nums[i-1]){
                nums[cnt]=nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};