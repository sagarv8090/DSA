class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        priority_queue<int>pq;
        for(auto i:gifts){
            pq.push(i);
        }
        while(k>0){
            int front=pq.top();
            pq.pop();
            int squareroot=sqrt(front);
            pq.push(squareroot);
            
            k--;
        }
        long long int sum=0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};