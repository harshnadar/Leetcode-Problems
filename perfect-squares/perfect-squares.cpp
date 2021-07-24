class Solution {
public:
    vector<int> dp;
    
    int solve(int n){
        if(n<=0) return 0;
        if(n==1) return 1;
        if(dp[n]!=1e5) return dp[n];
        int ans=1e5;
        for(int i=1;i<=100;i++){
            int temp_ans;
            if(i*i <= n){
                temp_ans=1+solve(n-i*i);
            }
            ans=min(ans, temp_ans);
        }
        return dp[n]=ans;
    }
    
    int numSquares(int n) {
        dp.resize(n+1,1e5);
        return solve(n);
    }
};