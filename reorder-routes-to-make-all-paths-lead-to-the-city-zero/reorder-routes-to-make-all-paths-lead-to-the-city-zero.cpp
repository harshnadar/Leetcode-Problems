class Solution {
public:
    vector<int> adj[50002];
    map<pair<int, int>, int > mp;
    bool vis[50002];
    
    void dfs(int src, int& count){
        vis[src]=true;
        for(auto it: adj[src]){
            if(!vis[it]){
                if(mp[{src,it}]==1){ count++; mp[{it,src}]=0;}
                dfs(it, count);
            }
        }
    }
    
    int minReorder(int n, vector<vector<int>>& connections) {
        for(auto it: connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            mp[{it[0],it[1]}] =1;
        }
        int count;
        dfs(0 , count);
        return count;
    }
};