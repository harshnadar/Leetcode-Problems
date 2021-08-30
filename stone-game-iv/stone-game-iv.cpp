class Solution {
public:
    bool winnerSquareGame(int n) {
        if(n==1) return true;
        if(n==2) return false;
        bool dp[n+1];
        memset(dp,false, sizeof dp);
        dp[0]=false;
        dp[1]=true;
        dp[2]=false;
        for(int i=3;i<n+1;i++){
            for(int j=1;j*j<=i;j++){
                if(dp[j*j]==true && dp[i-j*j]==true) dp[i]=false;
                else dp[i]=true;
                if(dp[i]==true) break;
            }
        }
        return dp[n];
        // return true;
    }
};