class Solution {
public:
    int minCut(string s) {
        int n=s.size();
        vector<int> dp(n+1, 1e5);
        dp[0]=-1;
        for(int i=0;i<n;i++){
            for(int len=0; i-len>=0 && i+len<n && s[i-len]==s[i+len]; len++){
                dp[i+len+1]= min(dp[i+len+1], dp[i-len]+1);
            }
            for(int len=0; i-len>=0 && i+len+1<n && s[i+len+1]==s[i-len]; len++){
                dp[i+len+2]= min(dp[i+len+2], dp[i-len]+1);
            }
        }
        return dp[n];
    }
};