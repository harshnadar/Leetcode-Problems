class Solution {
public:
    int func(int state, vector<vector<int> >& dist, int n){
        int cntCity=0, cntEdge=0, maxDist=0;
        for(int i=0;i<n;i++){
            if(((state>>i)&1) ==0) continue;
            cntCity++;
            for(int j=i+1;j<n;j++){
                if(((state>>j)&1) ==0) continue;
                cntEdge+=(dist[i][j]==1);
                maxDist = max(maxDist, dist[i][j]);
            }
        }
        if(cntCity-1 != cntEdge) return 0;
        return maxDist;
    }
    
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        vector<vector<int>> dist(n,vector<int>(n,n));
        
        for(auto it: edges){
            dist[it[0]-1][it[1]-1] = dist[it[1]-1][it[0]-1]=1;
        }
        for (int k = 0; k < n; k++){
            for (int i = 0; i < n; i++){
                for (int j = 0; j < n; j++){
                    dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]); 
                }
            }
        }
        
        vector<int> ans(n-1,0);
        for(int i=0;i<(1<<n);i++){
            int d=func(i,dist,n);
            // cout<<d<<endl;
            if(d>0) ans[d-1]++;
        }
        return ans;
    }
};