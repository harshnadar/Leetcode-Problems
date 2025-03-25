class Solution {
public:
    int dp[1002];
    int n;
    int solve(vector<int>& prices, int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];

        int a = prices[i]+solve(prices, i+i+2);
        for(int j=i+1;j<min(2*i+2,n);j++){
            a = min(a,prices[i]+solve(prices, j));
        }
        
        return dp[i] = a;
    }
    int minimumCoins(vector<int>& prices) {
        n = prices.size();
        memset(dp,-1,sizeof dp);
        return solve(prices, 0);
    }
};