class Solution {
public:
    int n; int m; int dp[52][52][12];
    int g[52][52];
    int mod = 1e9+7;
    
    int solve(int r, int c, int k){
        if(k==0) return g[r][c]>0;
        if(dp[r][c][k]!=-1) return dp[r][c][k];
        
        dp[r][c][k]=0;
        
        for(int i=r+1;i<n;i++){
            if(g[r][c]-g[i][c]>0 && g[i][c]>=k){
                dp[r][c][k] = (dp[r][c][k] + solve(i,c,k-1))%mod;
            }
        }
        
        for(int i=c+1;i<m;i++){
            if(g[r][c]-g[r][i]>0 && g[r][i]>=k){
                dp[r][c][k] = (dp[r][c][k] + solve(r,i,k-1))%mod;
            }
        }
        
        return dp[r][c][k];
    }
    
    int ways(vector<string>& pizza, int k) {
        n=pizza.size();
        m=pizza[0].size();
        memset(dp,-1,sizeof dp);
        
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                g[i][j] = g[i][j+1];
                for(int l=i;l<n;l++){
                    g[i][j]+=(pizza[l][j]=='A');
                }
            }
        }
        
        return solve(0,0,k-1);
    }
};