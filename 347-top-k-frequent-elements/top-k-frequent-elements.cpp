class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int> > >pq;
        map<int, int> cnt;
        for(auto &i: nums){
            cnt[i]++;
        }

        for(auto it: cnt){
            int num = it.first;
            int count = it.second;
            if(pq.size() < k){
                pq.push({count, num});
            }
            else{
                vector<int> top = pq.top();
                if(top[0] < count){
                    pq.pop();
                    pq.push({count, num});
                }
            }
        }
        vector<int > ans;
        while(!pq.empty()){
            ans.push_back(pq.top()[1]);
            pq.pop();
        }
        return ans;

    }
};