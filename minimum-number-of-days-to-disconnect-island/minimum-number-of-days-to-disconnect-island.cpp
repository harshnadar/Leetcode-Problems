class Solution {
public:
    vector<int> adj[904];
    vector<int> v;
    vector<int> vis;
    vector<int> in,low;
    int n, m;
    int timer;
    
    void dfsArticulation(int node, int par){
        vis[node] = true;
        in[node] = low[node] = timer++;
        int children=0;
        for (int it : adj[node]) {
            if (it == par) continue;
            if (vis[it]) {
                low[node] = min(low[node], in[it]);
            } else {
                dfsArticulation(it, node);
                low[node] = min(low[node], low[it]);
                if (low[it] >= in[node] && par!=-1)
                    v.push_back(node);
                ++children;
            }
        }
        if(par == -1 && children > 1)
            v.push_back(node);
    }
    
    void dfs(int i){
        vis[i]=true;
        for(auto it: adj[i]){
            if(!vis[it]) dfs(it);
        }
    }
    int minDays(vector<vector<int>>& grid) {
        n=grid.size();
        m=grid[0].size();
        int dx[]={1,0,0,-1};
        int dy[]={0,1,-1,0};
        int l=1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1) {grid[i][j]=l,l++;}
            }
        }
        if(l==2) return 1;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<4;k++){
                    int nx=i+dx[k];
                    int ny=j+dy[k];
                    if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                    if(grid[i][j] && grid[nx][ny]){
                        adj[grid[i][j]].push_back(grid[nx][ny]);
                    }
                }
            }
        }
        // for(int i=1;i<l;i++){
        //     cout<<i<<" ";
        //     for(auto it: adj[i]) cout<<it<<" ";
        //     cout<<endl;
        // }
        // cout<<l<<endl;
        vis.resize(l,false);
        int c=0;
        for(int i=1;i<l;i++){
            if(vis[i]==false){
                dfs(i);
                c++;
            }
        }
        if(c>1 || c==0) return 0;
        
        for(int i=0;i<l;i++){
            vis[i]=false;
        }
        in.resize(l,-1);
        low.resize(l,-1);
        
        for (int i = 1; i < l; ++i) {
            // cout<<vis[i]<<" ";
            if (!vis[i])
                dfsArticulation (i,-1);
        }
        // cout<<v.size();
    
        if(v.size()>0) return 1;
        return 2;
    }
};