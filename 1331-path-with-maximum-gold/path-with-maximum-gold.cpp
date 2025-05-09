class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int n,m;
    int val;

    int solve(vector<vector<int> >& grid, vector<vector<bool>>& vis, int i, int j){
        
        if(i<0 || j<0 || i>=n || j>=m || vis[i][j] || grid[i][j] == 0) return 0;
        vis[i][j] = true;
        int a = 0;
        for(int k=0;k<4;k++){
            a= max(a, grid[i][j] + solve(grid, vis, i+dx[k], j+dy[k]));
        }
        vis[i][j]=false;
        return a;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m = grid[0].size();
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) continue;
                vector<vector<bool> > vis(n, vector<bool>(m, false));
                ans = max(ans, solve(grid, vis, i, j));
            }
        }
        return ans;
    }
};