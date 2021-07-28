class Solution {
public:
    double dp[201][201];
    
    double solve(int a, int b){
        if(a<=0 && b<=0) return 0.5;
        if(a<=0) return 1;
        if(b<=0) return 0;
        if(dp[a][b]>0) return dp[a][b];
        dp[a][b]= 0.25*(solve(a-1,b-3)+ solve(a-2,b-2)+ solve(a-3,b-1)+ solve(a-4,b));
        return dp[a][b];
    }
    
    double soupServings(int n) {
        if(n>4800) return 1.000000;
        return solve((n+24)/25,(n+24)/25);
    }
};