bool cmp(vector<int>& a, vector<int>& b){
    return a[2]<b[2];
}
class Solution {
public:
    int par[100002];
    
    int find(int a){
        if(par[a]==a) return a;
        return par[a]=find(par[a]);
    }
    
    void uni(int a, int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        if(a<b) swap(a,b);
        par[b]=a;
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edge, vector<vector<int>>& queries) {
        int i=0,j=0;
        
        int q=queries.size();
        
        vector<vector<int> > qu;
        for(i=0;i<queries.size();i++){
            qu.push_back({queries[i][0],queries[i][1],queries[i][2],i});
        }
        sort(edge.begin(), edge.end(), cmp);
        sort(qu.begin(), qu.end(),cmp);
        
        for(i=0;i<n+1;i++){
            par[i]=i;
        }
        i=0;
        vector<bool> ans(q);
        while(i<q){
            while(j<edge.size() && edge[j][2]<qu[i][2]){
                uni(edge[j][0], edge[j][1]);
                j++;
            }
            if(find(qu[i][0]) == find(qu[i][1])) ans[qu[i][3]]=true;
            else ans[qu[i][3]]=false;
            i++;
        }
        return ans;
    }
};