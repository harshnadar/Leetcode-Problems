class Solution {
public:
    vector<int>adj[10002];
    int vis[100002];
    int dfsvis[100002];
    
    bool check(int node){
        vis[node]=1;
        dfsvis[node]=1;
        for(auto it:adj[node]){
            if(! vis[it]){
                if(check(it)) return true;
            }
            else if(dfsvis[it]) return true;
        }
        dfsvis[node]=false;
        return false;
    }
    
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        for(int i=0; i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(!check(i)) ans.push_back(i);
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};