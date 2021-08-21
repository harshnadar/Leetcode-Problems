class Solution {
public:
    int dp[5002];
    
    int change(int amount, vector<int>& coins) {
        // int[] dp = new int[amount+1]; 
        dp[0]=1;
        for(int i=0; i<coins.size(); i++)
            for(int j=1;j<=amount;j++) 
                dp[j] = dp[j] + (coins[i]<=j ? dp[j-coins[i]] : 0);
        return dp[amount];
    }
};