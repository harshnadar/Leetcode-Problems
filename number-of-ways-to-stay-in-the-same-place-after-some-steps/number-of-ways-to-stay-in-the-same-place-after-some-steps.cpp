class Solution {
public:
    map<pair<int, int>, long long int > dp;
    const int mod=1e9+7;
    
    long long int solve(int n, int i, int len){
        if(n==0 && i==0) return 1;
        if(i<0 || i>=len || n==0 || i>n) return 0;
        // cout<<dp.count({n,i})<<"\n";
        if(dp.count({n,i})>0) return dp[{n,i}];
        long long int res=0;
        // cout<<((solve(n-1,i,len)%mod+ solve(n-1, i-1, len)%mod+ solve(n-1, i+1, len)%mod)%mod)<<"\n";
        
        res=((solve(n-1,i,len)%mod+ solve(n-1, i-1, len)%mod+ solve(n-1, i+1, len)%mod)%mod);
        
        return dp[{n,i}]=res%mod;
    }
    
    int numWays(int steps, int arrlen) {
        long long int count=0;
        count=solve(steps,0,arrlen);
        count%=mod;
        return (int)count;
        // return 1;
    }
};