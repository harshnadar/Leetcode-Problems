class Solution {
public:
    
    bool dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int i, int j, int n, int m, vector<vector<bool>>& vis){
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid2[i][j]==0) return true;
        bool res=true;
        vis[i][j]=true;
        if(grid1[i][j]==0) res=false;
        res= dfs(grid1, grid2, i+1,j, n, m, vis) and res;
        res= dfs(grid1, grid2, i-1,j, n, m, vis) and res;
        res= dfs(grid1, grid2, i,j+1, n, m, vis) and res;
        res= dfs(grid1, grid2, i,j-1, n, m, vis) and res;
        return res;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid1.size();
        int m=grid1[0].size();
        vector<vector<bool> > vis(n+5, vector<bool>(m+5, false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid2[i][j] && !vis[i][j] && dfs(grid1, grid2, i,j, n, m, vis)) count++;
            }
        }
        return count;
        
    }
};