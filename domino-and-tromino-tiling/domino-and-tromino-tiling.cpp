class Solution {
public:
    vector<long long int> dp;
    const int mod=1e9+7;
    
    int numTilings(int n) {
        dp.resize(n+5);
        dp[0]==1, dp[1]=1;
        dp[2]=2; dp[3]=5;
        for(int i=4;i<n+1;i++){
            dp[i]=2*dp[i-1]+dp[i-3];
            dp[i]%=mod;
        }
        return (int)dp[n];
    }
};