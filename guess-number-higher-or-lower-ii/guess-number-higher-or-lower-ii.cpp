class Solution {
public:
    int dp[201][201];
    
    int solve(int l, int r){
        if(l>=r) return 0;
        
        if(dp[l][r]!=-1) return dp[l][r];
        
        int ans =1e8;
        
        for(int j=l;j<=r;j++){
            ans = min(ans, j+max(solve(l,j-1), solve(j+1,r)));
        }
        
        return dp[l][r]= ans;
    }
        
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof dp);
        
        return solve(1,n);
    }
};