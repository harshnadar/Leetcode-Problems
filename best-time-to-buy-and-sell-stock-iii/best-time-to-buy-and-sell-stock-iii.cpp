class Solution {
public:
    int dp[100002][2][3];
    int n;
    
    int solve(vector<int>& prices, int i, int c, int k){
        if(i>=n || k==0) return 0;
        
        if(dp[i][c][k]!=-1) return dp[i][c][k];
        
        if(c){
            int p1 = prices[i]+solve(prices,i+1,!c,k-1);
            int p2 = solve(prices,i+1,c,k);
            
            return dp[i][c][k] = max(p1,p2);
        }
        else{
            int p1 = -prices[i]+solve(prices,i+1,!c,k);
            int p2 = solve(prices, i+1,c,k);
            
            return dp[i][c][k] = max(p1,p2);
        }
        
        return dp[i][c][k];
        
    }
    
    int maxProfit(vector<int>& prices) {
        n=prices.size();
        memset(dp,-1,sizeof dp);
        return solve(prices, 0, 0,2);
    }
};