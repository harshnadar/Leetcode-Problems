#define pb push_back
class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int,int>> adj[n];
        for(auto it: flights){
            adj[it[0]].push_back({it[1], it[2]});
        }
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
        vector<int> dist(n,INT_MAX);
        pq.push({0,src,0});
        while(!pq.empty()){
            vector<int> v = pq.top();
            pq.pop();
            if(dst==v[1]) return v[0];
            if(v[2]>k) continue;
            if(dist[v[1]]!=INT_MAX){
                if(dist[v[1]]<v[2]) continue;
            }
            dist[v[1]]=v[2];
            for(auto it: adj[v[1]]){
                pq.push({it.second+v[0], it.first, v[2]+1});
            }
        }
        return -1;
    }
};