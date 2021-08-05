
class Solution {
public:
    void islandcolor(int i,int j,vector<vector<int>> &island,int n)
    {
        if(i<0 or i>=n or j<0 or j>=n or island[i][j]==1)
            return;
        island[i][j]=1;
        islandcolor(i+1,j,island,n);
        islandcolor(i,j+1,island,n);
        islandcolor(i-1,j,island,n);
        islandcolor(i,j-1,island,n);
    }
    int regionsBySlashes(vector<string>& grid) {
        int n=grid.size();
        vector<vector<int>> island(3*n,vector<int> (3*n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='/'){
                    island[i * 3][j * 3 + 2] = 1;
                    island[i * 3 + 1][j * 3 + 1] = 1;
                    island[i * 3 + 2][j * 3] = 1;
                }
                else if(grid[i][j]=='\\'){
                    island[i * 3][j * 3] = 1;
                    island[i * 3 + 1][j * 3 + 1] = 1;
                    island[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }
        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
                cout<<island[i][j]<<" ";
            }
            cout<<"\n";
        }
        int ans=0;
        for(int i=0;i<3*n;i++)
        {
            for(int j=0;j<3*n;j++)
            {
                if(island[i][j]==0)
                {
                    ans++;
                    islandcolor(i,j,island,3*n);
                }
            }
        }
        return ans;
    }
};