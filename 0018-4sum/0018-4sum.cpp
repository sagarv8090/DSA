class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        set<vector<int>>s;
        for(int i=0;i<n;i++){
            
            for(int j=i+1;j<n;j++){

                int left=j+1;
                int right=n-1;
                while(left<right){
                   long long int sum=0;
                   sum+=nums[i];
                   sum+=nums[j];
                   sum+=nums[left];
                   sum+=nums[right];
                    if(sum==target){
                        vector<int>temp{nums[i],nums[j],nums[left],nums[right]};
                        s.insert(temp);
                        while(left<right && nums[left]==nums[left+1])left++;
                        while(left<right &&nums[right]==nums[right-1])right--;
                        left++;
                        right--;
                    }
                    else if(sum<target)left++;
                    else right--;
                }
            }
        }
        vector<vector<int>>ans(s.begin(),s.end());
        return ans;
    }
};
