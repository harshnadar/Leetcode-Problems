#define f(a,b,i) for(int i=a;i<b;i++)

int dx[]={-1,1,0,0};
int dy[]={0,0,1,-1};


class Solution {
public:
    int n;
    void dfs(int i, int j, set<pair<int, int> >& st, vector<vector<int> >& grid){
        if(i<0 || i>=n || j<0 || j>=n || grid[i][j]==0) return;
        st.insert({i,j});
        for(int k=0;k<4;k++){
            int nx=i+dx[k];
            int ny=j+dy[k];
            if(st.find({nx,ny})==st.end())
            dfs(nx,ny,st,grid);
        }
    }
    
    int shortestBridge(vector<vector<int>>& grid) {
        set<pair<int,int> > A, B;
        n=grid.size();
        f(0,n,i){
            f(0,n,j){
                if(grid[i][j]==0) continue;
                if(A.empty()){
                    dfs(i,j,A,grid);
                }
                else if(A.find({i,j})==A.end() && B.empty()){
                    dfs(i,j,B,grid);
                }
            }
        }
        int ans=INT_MAX;
        for(auto it: A){
            for(auto itr: B){
                ans=min(ans, abs(it.first-itr.first)+abs(it.second-itr.second)-1);
            }
        }
        return ans;
    }
};