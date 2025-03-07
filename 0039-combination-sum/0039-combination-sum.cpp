class Solution {
    private:
    void solve(int ind,vector<int>& candidates,int target,vector<vector<int>>&ans,vector<int>&temp){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        if (ind < 0 || target < 0) {
            return; // Stop recursion if out of bounds or negative target
        }
        //not taking element
         solve(ind-1,candidates,target,ans,temp);

        //taking element
        temp.push_back(candidates[ind]);
         solve(ind,candidates,target-candidates[ind],ans,temp);
        temp.pop_back();

        
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<vector<int>>ans;
        vector<int>temp;
         solve(n-1,candidates,target,ans,temp);
         return ans;
    }
};