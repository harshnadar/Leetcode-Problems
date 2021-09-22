class Solution {
public:
    int dp[51][51][101];
    int mod = 1e9+7;
    int n,m,k;
    
    long long int solve(int i, int curCost, int curMax){
        if(i==n){
            return curCost==k;
        }
        if(dp[i][curCost][curMax]!=-1) return dp[i][curCost][curMax];
        
        long long int ans = 0;
        
        ans+= ((long long)curMax*solve(i+1,curCost, curMax))%mod;
        
        if(curCost+1<=k){
            for(int num = curMax+1;num<=m;num++){
                ans+=solve(i+1, curCost+1, num);
                ans%=mod;
            }
        }
        return dp[i][curCost][curMax]=ans;
    }
    
    int numOfArrays(int n, int m, int k) {
        if(m<k) return 0;
        memset(dp,-1,sizeof dp);
        this->n = n;
        this->m = m;
        this->k = k;
        
        return solve(0,0,0);
    }
};