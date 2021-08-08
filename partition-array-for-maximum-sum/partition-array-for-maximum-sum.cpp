class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        int dp[n+1];
        memset(dp,0,sizeof dp);
        for(int i=1;i<=n;i++){
            int cursum=0;
            for(int j=1;j<=k && i-j>=0;j++){
                cursum=max(arr[i-j], cursum);
                dp[i]=max(dp[i],dp[i-j]+cursum*j);
            }
        }
        for(int i=0;i<n+1;i++) cout<<i<<" "<<dp[i]<<"\n";
        return dp[n];
    }
};