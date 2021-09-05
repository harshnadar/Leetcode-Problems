
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& env) {
        int n=env.size();
        sort(env.begin(), env.end());
        vector<int> dp(n+1,1);
        dp[0]=1;
        
        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(env[i][0]>env[j][0] && env[i][1]>env[j][1]){
                    dp[i]=max(dp[i], dp[j]+1);
                }
                // else dp[i]=max(dp[i],dp[i-1]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};