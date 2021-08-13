class Solution {
public:
    int n,m;
    
    int dfs(int i, int j, vector<vector<int> >& grid){
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]!=1) return 0;
        grid[i][j]=-1;
        int c=0;
        c=1+dfs(i-1,j,grid)+ dfs(i+1,j,grid) + dfs(i,j-1,grid) + dfs(i,j+1,grid);
        return c;
    }
    
    int numEnclaves(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if((i==0 || j==0 || i==n-1 || j==m-1) && grid[i][j]==1){
                    dfs(i,j,grid);
                }
            }
        }
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    count+=dfs(i,j,grid);
                }
            }
        }
        return count;
    }
};