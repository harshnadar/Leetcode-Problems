class Solution {
public:
    vector<int> adj[205];
    int vis[205];
    void dfs(int i){
        vis[i]=true;
        for(auto it: adj[i]){
            if(vis[it]==false) dfs(it);
        }
    }
    
    int findCircleNum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        if(n==1) return 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(vis[i]==false){
                dfs(i);
                c++;
            }
        }
        return c;
    }
};