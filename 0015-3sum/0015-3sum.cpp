class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int i=0;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        set<vector<int>>st;
        while(i<n){
            int j=i+1;
            int k=n-1;
            while(j<k){
            int sum=nums[i]+nums[j]+nums[k];
            if(sum==0){
                 st.insert({nums[i],nums[j],nums[k]});
                 while(j<k && nums[j]==nums[j+1]){
                    j++;
                 }
                 while(j<k && nums[k]==nums[k-1]){
                    k--;
                 }
                 j++;
                 k--;
            }
            else if(sum<0){
                j++;
            }
            else{
                k--;
            }
            }
            i++;
        }
    vector<vector<int>>ans(st.begin(),st.end());
    return ans;
    }
};