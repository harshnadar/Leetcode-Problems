int dx[]={0,0,1,-1};
int dy[]={1,-1,0,0};
    
class Solution {
public:
    int n,m;
    
    int check(vector<vector<bool> >& vis){
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==false) return 0;
            }
        }
        return 1;
    }
    
    int solve(int i, int j, vector<vector<int> >& grid, vector<vector<bool> >& vis){
        if(i<0 || i>=n || j<0 || j>=m || vis[i][j]==true) return 0;
        vis[i][j]=true;
        if(grid[i][j]==2){
            if(check(vis)==0){
                vis[i][j]=false;
                return 0;
            }
            else{ vis[i][j]=false; return 1;}
        }
        int ans= 0;
        
        for(int k=0;k<4;k++){
            int nx = i+dx[k];
            int ny = j+dy[k];
            
            ans+=solve(nx,ny,grid,vis);
            
        }
        vis[i][j]=false;
        return ans;
    }    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        vector<vector<bool> > vis(n,vector<bool>(m,false));
        int x,y;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-1) vis[i][j]=true;
                if(grid[i][j]==1) x=i,y=j;
            }
        }
        return solve(x,y,grid,vis);
    }
};