class Solution {
public:
    int search(vector<int>& nums, int target) {
        int start=0;
        int end=nums.size()-1;
        while(start<=end){
            int mid=(start+end)/2;
            if(target==nums[mid])return mid;
            //sorted left side
            if(nums[mid]>=nums[start]){
                //if target in sorted left side
                if(target>=nums[start] && target<=nums[mid]){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            //sorted right side
            else{
                //if target in sorted right side
                if(target<=nums[end] && target>=nums[mid]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    }
};