class Solution {
public:  
    int dp[5002];
    int change(int amount, vector<int>& coins) {
        dp[0]=1;
        int n=coins.size();
        for(int i=0;i<n;i++){
            for(int j=1;j<=amount;j++){
                if(coins[i]<=j)
                dp[j]+=dp[j-coins[i]];
            }
        }
        return dp[amount];
    }
};