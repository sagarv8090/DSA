class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        vector<int>x;
        int cnt=0;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            if(nums[i]==val){
               cnt++;
            }
            else{
                x.push_back(nums[i]);
            }
          
        }
        nums=x;
        return n-cnt;
    }
};