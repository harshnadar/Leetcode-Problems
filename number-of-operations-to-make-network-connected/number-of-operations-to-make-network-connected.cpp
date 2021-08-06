class Solution {
public:
    vector<vector<int> > adj;
    bool vis[(int)1e5+1];
    
    void dfs(int i){
        vis[i]=true;
        for(auto it: adj[i]){
            if(!vis[it]){
                dfs(it);
            }
        }
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(n-1 > connections.size()) return -1;
        adj.resize(n+1);
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int cc=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(i);
                cc++;
            }
        }
        cout<<cc;
        return cc-1;
    }
};