#define ll long long int
class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        
        int mod = 1e9+7;
        
        vector<pair<int,int> > adj[n+1];
        vector<ll> dist(n, LONG_MAX);
        // for(int i=0;i<n;i++) cout<<dist[i]<<" ";
        vector<ll> ways(n,0);
        
        for(auto edge: roads){
            adj[edge[0]].push_back({edge[1], edge[2]});
            adj[edge[1]].push_back({edge[0], edge[2]});
        }
        
        priority_queue<pair<ll, ll>, vector<pair<ll,ll> >, greater<pair<ll,ll> > > pq;
        
        pq.push({0,0});
        
        dist[0]=0;
        ways[0]=1;
        
        while(!pq.empty()){
            int cur = pq.top().second;
            ll cur_d = pq.top().first;
            
            pq.pop();
            
            if(cur_d > dist[cur]) continue;
            
            for(auto it: adj[cur]){
                int x = it.first;
                ll y = cur_d + it.second;
                // cout<<y<<" "<<dist[cur]<<"\n";
                
                if(y< dist[x]){
                    dist[x]=y;
                    pq.push({y,x});
                    ways[x]=ways[cur];
                    // cout<<"HI\n";
                }
                else if(dist[x]==y){
                    ways[x] = (ways[x]+ways[cur])%mod;
                }
            }
        }
        return ways[n-1];
    }
};