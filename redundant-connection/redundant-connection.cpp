class Solution {
    int par[1002];
public:
    int find(int a){
        if(par[a]==-1) return a;
        return par[a]=find(par[a]);
    }
    
    bool uni(int a, int b){
        a=find(a);
        b=find(b);
        if(a==b) return true;
        par[a]=b;
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        memset(par,-1,sizeof par);
        for(auto it: edges){
            if(uni(it[0],it[1])) return it;
        }
        return edges[0];
    }
};