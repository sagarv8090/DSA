class Solution {
    private:
    void solve(int index, vector<int>&candidates,vector<int>&temp,set<vector<int>>&s,int target,int n){
        if(index>=n || target<0){
            if(target==0){
            s.insert(temp);
            }
            return;
        }
        //pick
        temp.push_back(candidates[index]);
        solve(index,candidates,temp,s,target-candidates[index],n);

        //not pick
        temp.pop_back();
        solve(index+1,candidates,temp,s,target,n);

    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        set<vector<int>>s;
        int n=candidates.size();
        solve(0,candidates,temp,s,target,n);
        vector<vector<int>>res(s.begin(),s.end());
        return res;
    }
};