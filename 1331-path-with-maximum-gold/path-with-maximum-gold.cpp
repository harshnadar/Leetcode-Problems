class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int n,m;
    int val;

    int solve(vector<vector<int> >& grid, int i, int j){
        
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 0) return 0;
        int orig = grid[i][j];
        grid[i][j] = 0;
        int a = 0;
        for(int k=0;k<4;k++){
            a= max(a, orig + solve(grid, i+dx[k], j+dy[k]));
        }
        grid[i][j]=orig;
        return a;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        this->n = grid.size();
        this->m = grid[0].size();
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0) continue;
                ans = max(ans, solve(grid, i, j));
            }
        }
        return ans;
    }
};