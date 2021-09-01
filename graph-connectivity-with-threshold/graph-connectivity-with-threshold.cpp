class Solution {
public:
    int par[10002];
    int sz[10002];
    
    int find(int a){
        if(par[a]==a) return a;
        return par[a]=find(par[a]);
    }
    
    void uni(int a, int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(sz[a]<sz[b]) swap(a,b);
        par[b]=a;
        sz[a]+=sz[b];
    }
    
    vector<bool> areConnected(int n, int threshold, vector<vector<int>>& queries) {
        for(int i=1;i<n+1;i++){
            sz[i]=1;
            par[i]=i;
        }
        unordered_map<int, int> mp;
        for(int x=threshold+1;x<n+1;x++){
            int m=1;
            while(m*x<=n){
                uni(x*m,x);
                m++;
            }
        }
        for(int i=1;i<n+1;i++) cout<<find(i)<<endl;
        vector<bool> ans;
        for(auto q: queries){
            if(find(q[0]) == find(q[1])) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};