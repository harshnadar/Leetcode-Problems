class Solution {
public:
    long long int dp[1002][1002];
    int n;
    vector<int> dist;
    int s;
    
    long long int dfs(int i, int k){
        if(k<0) {return 1e9;}
        
        if(i<0) return 0;
        
        if(dp[i][k]!=-1) return dp[i][k];
        
        return dp[i][k] = dist[i] + min(dfs(i-1,k-1), ((dfs(i-1,k)+(s-1))/s)*s);
    }
    
    int minSkips(vector<int>& dist, int s, int h) {
        long long int sum =accumulate(dist.begin(), dist.end(), 0);
        
        if(sum>(long long)h*s) return -1;
        
        this->s = s;
        
        n=dist.size();
        this->dist = dist;
        memset(dp,-1,sizeof dp);
        
        for(int k=0;k<n+1;k++){
            if(dfs(n-1,k)<=(long long)h*s) return k;
        }
        return -1;
    }
};