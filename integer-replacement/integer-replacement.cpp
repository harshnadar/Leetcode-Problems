class Solution {
public:
    map<int,long long int> dp;
    
    long long int solve(long long int n){
        if(n==1) return 0;
        if(dp[n]!=0) return dp[n];
        
        if(n%2) return dp[n] = min(solve((n-1)/2)+(long long)2, solve((n+1)/2)+(long long)2);
        else return dp[n] =  solve(n/2)+1;
        return dp[n];
    }
    int integerReplacement(int n) {
        
        dp[1]=0;
        return solve(n);
    }
};