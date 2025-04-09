class Solution {
public:
    int findDuplicate(vector<int>& nums) {
      int n=nums.size();
         vector<int>ans(n,0);
  int x;
  for(int i=0;i<n;i++){
    ans[nums[i]]++;
  }
  for(int i=0;i<n;i++){
    if(ans[i]>=2){
      x=i;
    }
  }
  return x;
    }
};