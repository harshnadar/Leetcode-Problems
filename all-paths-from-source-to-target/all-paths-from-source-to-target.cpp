class Solution {
public:
    vector<int> adj[16];
    vector<vector<int> > v;
    vector<int> temp;
    
    void dfs(int node, int dest){
        temp.push_back(node);
        if(node==dest){
            v.push_back(temp);
            temp.pop_back();
            return;
        } 
        for(auto it:adj[node]){
            dfs(it,dest);
        }
        temp.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n=graph.size();
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        dfs(0,n-1);
        return v;
    }
};