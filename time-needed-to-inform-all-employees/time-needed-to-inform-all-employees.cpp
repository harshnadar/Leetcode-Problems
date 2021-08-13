class Solution {
public:
    vector<int> adj[100002];
    bool vis[100002];
    
    int dfs(int src, vector<int>& inform){
        vis[src] = true;
        int c=0;
        int tmp_ans=0;
        for(auto it: adj[src]){
            if(!vis[it]){
                tmp_ans = max(inform[src]+dfs(it,inform), tmp_ans);
            }
        }
       c=tmp_ans;
        return c;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& inform) {
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
                adj[i].push_back(manager[i]);
                adj[manager[i]].push_back(i);
            }
        }
        int ans=0;
        vis[headID]=true;
        for(auto it: adj[headID]){
            if(!vis[it]){
                ans=max(ans, inform[headID]+dfs(it, inform));
            }
        }
        return ans;
    }
};