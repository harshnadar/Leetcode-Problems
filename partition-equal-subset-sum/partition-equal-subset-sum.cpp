class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(), nums.end(),0);
        int sum=total/2;
        vector<vector<int> > dp(n+1, vector<int>(sum+1,0));
        for(int i=1;i<n+1;i++){
            for(int j=1;j<sum+1;j++){
                if(nums[i-1]>j) dp[i][j]=dp[i-1][j];
                else{
                    dp[i][j]=max(dp[i-1][j-nums[i-1]]+nums[i-1], dp[i-1][j]);
                }
            }
        }
        return (total-2*dp[n][sum])==0;
    }
};