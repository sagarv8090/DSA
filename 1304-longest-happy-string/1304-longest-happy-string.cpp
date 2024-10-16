class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans="";
        priority_queue<pair<int,char>>pq;
        if(a>0)pq.push({a,'a'});
        if(b>0)pq.push({b,'b'});
        if(c>0)pq.push({c,'c'});

        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            int cnt1=it.first;
            int char1=it.second;
            int n=ans.size();
            if(n>=2 && ans[n-1]==char1 && ans[n-2]==char1){
                if(pq.empty())break;
                auto it=pq.top();
                pq.pop();
                int cnt2=it.first;
                int char2=it.second;
                ans+=char2;
                cnt2--;
                if(cnt2>0)pq.push({cnt2,char2});
                pq.push({cnt1,char1});
            }
            else{
                ans+=char1;
                cnt1--;
                if(cnt1>0)pq.push({cnt1,char1});
            }
        }
        return ans;
    }
};