class Solution {
public:
    int dp[102][102];
    int presum[102];
    int n;
    
    int solve(int i, int m, vector<int>& piles){
        if(i+2*m >= n) return presum[i];
        if(dp[i][m]!=-1) return dp[i][m];
        int res=0;
        for(int j=1;j<=2*m;j++){
            int take= presum[i]-presum[i+j];
            res= max(res, take+presum[i+j]- solve(i+j,max(j,m), piles));
        }
        return dp[i][m]=res;
        
    }
    
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof dp);
        presum[n-1] = piles[n-1];
        for(int i=n-2;i>=0;i--){
            presum[i]=piles[i]+presum[i+1];
        }
        for(int i=0;i<n;i++){
            cout<<presum[i]<<"\n";
        }
        return solve(0,1,piles);
    }
};