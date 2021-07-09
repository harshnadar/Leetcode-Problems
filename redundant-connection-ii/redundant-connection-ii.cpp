class Solution {
public:
    vector<int> par;
    
    int find(int a){
        if(par[a]==a) return a;
        return par[a]=find(par[a]);
    }
    
    void uni(int a, int b){
        a=find(a);
        b=find(b);
        par[a]=b;
    }
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        par.resize(n+1);
        vector<int> in(n+1,0);
        for(auto it:edges){
            in[it[1]]++;
        }
        vector<int> ans(2);
        for(int i=0;i<n;i++){
            for(int j=0;j<=n;j++){
                par[j]=j;
            }
            in[edges[i][1]]--;
            int cycle=0, check=0;
            for(int j=0;j<n;j++){
                if(i==j) continue;
                int x=edges[j][0], y=edges[j][1];
                if(in[x]>1 || in[y]>1) check=1;
                if(find(x)==find(y)) cycle=1;
                else uni(find(x),find(y));
            }
            if(!check && !cycle)
                ans[0]=edges[i][0], ans[1]=edges[i][1];
            in[edges[i][1]]++;
        }
        return ans;
    }
};