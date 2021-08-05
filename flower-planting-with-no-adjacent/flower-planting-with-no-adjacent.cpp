class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        int m=paths.size();
        vector<int> adj[n+1];
        for(auto it: paths){
            adj[it[0]-1].push_back(it[1]-1);
            adj[it[1]-1].push_back(it[0]-1);
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            int color[5]={};
            for(auto it: adj[i]){
                color[ans[it]]=1;
            }
            for(int c=4;c>0;c--){
                if(color[c]==0) ans[i]=c;
            }
        }
        return ans;
    }
};