class Solution {
public:
    vector<int> minOperations(string boxes) {
        int n=boxes.size();
        vector<int>storeInd;
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(boxes[i]=='1'){
                storeInd.push_back(i);
            }
        }
        for(int i=0;i<n;i++){
            int temp=0;
            for(int j=0;j<storeInd.size();j++){
                temp+=abs(i-storeInd[j]);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};