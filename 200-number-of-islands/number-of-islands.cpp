class Solution {
public:
    int n,m;
    vector<vector<int>> movements = {{1,0}, {0,1}, {-1,0}, {0,-1}};

    void dfs(vector<vector<char>>& grid, int i, int j){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == '0') return;

        grid[i][j] = '0';

        for(auto it: movements){
            dfs(grid, i+it[0], j+it[1]);
        }
    
    }



    int numIslands(vector<vector<char>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;

        for(int i = 0;i<n;i++){
            for(int j = 0; j<m;j++){
                if(grid[i][j] == '1') {dfs(grid, i, j); count++;}
            }
        }
         

        return count;
    }
};