class Solution {
    public:
        static int waysToSplitArray(vector<int>& nums) {
        long long sum=accumulate(nums.begin(), nums.end(), 0LL);
        return count_if(nums.begin(), nums.end()-1, [acc=0LL, sum](int x) mutable{
            acc+=x;
        return 2*acc>=sum;
    });
    }
};



        
    