class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<long long>pq(nums.begin(),nums.end());
        long long ans=0;
        while(k>0){
            long long ele=pq.top();
            pq.pop();
            ans+=ele;
            if(ele%3==0){
                pq.push(ele/3);
            }
            else{
                pq.push(ele/3+1);
            }
            k--;
        }
        return ans;
    }
};