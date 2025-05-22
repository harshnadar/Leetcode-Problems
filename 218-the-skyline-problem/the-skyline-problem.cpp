class Solution {
public:

    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        priority_queue<pair<int, int>, vector<pair<int,int> >, greater<pair<int, int> > > pq;
        for(auto it: buildings){
            pq.push({it[0], -it[2]});
            pq.push({it[1], it[2]});
        }
        pair<int, int> curr({0,0});
        multiset<int> h({0});
        vector<vector<int> > ans;

        while(!pq.empty()){
            pair<int, int> p = pq.top();
            pq.pop();
            if(p.second < 0){
                h.insert(-p.second);
            }
            else{
                h.erase(h.find(p.second));
            }
            if(*h.rbegin() != curr.second){
                curr.first = p.first;
                curr.second = *h.rbegin();
                ans.push_back({curr.first, curr.second});
            }
        }
        return ans;

    }
};