class Solution {
public:
    vector<int> dist;
    vector<pair<int, int> > adj[1002];
    
    void dij(int src){
        priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        pq.push({0,src});
        dist[src]=0;
        while(!pq.empty()){
            int cur=pq.top().second;
            int cur_d=pq.top().first;
            pq.pop();
            if(cur_d > dist[cur]){
                continue;
            }
            for(auto edge: adj[cur]){
                int x=edge.first;
                int y=edge.second;
                if(cur_d+y < dist[x]){
                    dist[x]=cur_d+y;
                    pq.push({dist[x],x});
                }
            }
        }
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        dist.resize(n+1,INT_MAX);
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        dij(k);
        dist[0]=0;
        for(int i=1;i<=n;i++){
            if(dist[i]==INT_MAX) return -1;
        }
        return *max_element(dist.begin(),dist.end());
    }
};