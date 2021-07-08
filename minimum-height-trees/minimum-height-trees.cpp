class Solution {
public:
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if(n==1) return vector<int> ({0});
        if(n==2){return edges[0];}
        
        vector<int> adj[n+1];
        int in[n+1];
        memset(in,0,sizeof in);
        
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
            in[it[1]]++;
            in[it[0]]++;
        }
        vector<int> q;
        for(int i=0;i<n;i++){
            if(in[i]<=1){
                q.push_back(i);
                in[i]=0;
            }
        }
        int tl=q.size();
        cout<<q.size()<<'\n';
        while(tl<n){
            vector<int> v;
            for(auto cur:q){
                for(auto child: adj[cur]){
                    in[child]--;
                    if(in[child]==1){
                        v.push_back(child);
                    }
                }
            }
            
            tl+=v.size();
            q=v;
        }
       
        
        return q;
    }
};