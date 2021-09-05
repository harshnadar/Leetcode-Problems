class Solution {
public:
    int firstDayBeenInAllRooms(vector<int>& next) {
        int n=next.size();
        int mod = 1e9+7;
        vector<long long int> dp(n+1);
        dp[0]=0;
        for(int i=1;i<n;i++){
            dp[i]=((long)2 + 2*dp[i-1] - dp[next[i-1]] + mod)%mod;
        }
        return dp[n-1];
    }
};