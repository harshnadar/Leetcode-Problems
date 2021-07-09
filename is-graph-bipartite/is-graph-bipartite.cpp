#define pb push_back
#define f(a,b,i) for(int i=a;i<b;i++)
class Solution {
public:    
    vector<int> adj[102];
    vector<bool> vis;
    vector<int> col;
    
    bool check(int v, int c){
        vis[v]=1;
        col[v]=c;
        for(auto child: adj[v]){
            if(vis[child]==0){
                if(check(child,c^1)==false){
                    return false;
                }
            }
            else{
                if(col[v]==col[child]) return false;
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vis.resize(n+1,false);
        col.resize(n+1,0);
        f(0,n,i){
            for(auto it:graph[i]){
                adj[i].push_back(it);
            }
        }
        f(0,n,i){
            if(vis[i]==false){
                if(!check(i,0)) return false;
            }
        }
        return true;
    }
};