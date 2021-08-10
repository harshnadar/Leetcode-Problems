int dx[]={1,-1,0,0};
int dy[]={0,0,-1,1};

class Solution {
public:
    int n;
    int dfs(int i, int j, vector<vector<int> >& grid, int id){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]!=1) return 0;
        grid[i][j]=id;
        return 1+ dfs(i+1,j,grid,id)+ dfs(i-1,j,grid,id)+ dfs(i,j+1,grid, id)+ dfs(i,j-1,grid, id);
    }
    
    
    int largestIsland(vector<vector<int>>& grid) {
        n=grid.size();
        map<int, int> mp;
        int id=2;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int size = dfs(i, j, grid, id);
                    mp[id]=size;
                    id++;
                }
            }
        }
        int res = mp[2];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    set<int> s;
                    s.insert((i>0)?grid[i-1][j]:0);
                    s.insert((j>0)?grid[i][j-1]:0);
                    s.insert((j<n-1)?grid[i][j+1]:0);
                    s.insert((i<n-1)?grid[i+1][j]:0);
                    
                    int total=1;
                    for(auto it: s){
                        total+=mp[it];
                    }
                    
                    res=max(res, total);
                }
            }
        }
        return res;
    }
};