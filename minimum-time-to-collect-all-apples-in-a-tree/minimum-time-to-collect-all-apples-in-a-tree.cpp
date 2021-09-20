class Solution {
public:
    int timer=0;
    vector<int> adj[100002];
    vector<bool> hasApple;

    bool vis[100002];
    
    int dfs(int node, int mycost){
        vis[node]=true;
        int cost = 0;
        for(auto it: adj[node]){
            if(!vis[it]){
                cost+=dfs(it,2);
            }
        }
        if(cost==0 && hasApple[node]==false) return 0;
        
        return cost+mycost;
    }
    
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        int m=edges.size();
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        this->hasApple = hasApple;
        return dfs(0,0);
        
    }
};