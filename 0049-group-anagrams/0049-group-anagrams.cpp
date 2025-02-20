class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>>groupanagram;
        for(int i=0;i<strs.size();i++){
            string sorted=strs[i];
            sort(sorted.begin(),sorted.end());
            groupanagram[sorted].push_back(strs[i]);
        }
        vector<vector<string>>ans;
        for(auto &it:groupanagram){
            ans.push_back(it.second);
        }
        return ans;
    }
};