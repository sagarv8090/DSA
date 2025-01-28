class Solution {
    private:
    vector<int> binarysearch(vector<int>& nums,int start,int last,int target,vector<int>&ans){
        int n=nums.size();
while(start<=last){
   int  mid=start+(last-start)/2;
    if(nums[mid]==target){
        int x=mid;
        int y=mid;
        while(x-1>=0 && nums[x]==nums[x-1]){
            x--;
            continue;
        }
        ans.push_back(x);
        while(y+1<=n-1 &&nums[y]==nums[y+1]){
            y++;
            continue;
        }
        ans.push_back(y);
        return ans;

    }
    else if(nums[mid]>target){
        last=mid-1;
    }
    else{
        start=mid+1;
    }
}
return {-1,-1};
}
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans;
        int n=nums.size();
        int start=0;
        int last=n-1;
        return binarysearch(nums,start,last,target,ans);
    }
};