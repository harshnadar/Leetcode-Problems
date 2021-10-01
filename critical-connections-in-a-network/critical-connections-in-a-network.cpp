class Solution {
public:
    map<int, vector<int> > adj;
    int in[100002], low[100002], vis[100002];
    int timer;
    vector<vector<int> > res;
    
    void dfs(int node,int par){
        vis[node]=1;
        in[node]=low[node]=timer;
        timer++;
        for(auto child: adj[node]){
            if(child==par) continue;
            if(vis[child]==1){
                low[node] = min(low[node], in[child]);
            }
            else{
                dfs(child, node);
                if(low[child]>in[node]){
                    res.push_back({child,node});
                }
                low[node] = min(low[node], low[child]);
            }
        }
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        dfs(0,-1);
        
        return res;
    }
};