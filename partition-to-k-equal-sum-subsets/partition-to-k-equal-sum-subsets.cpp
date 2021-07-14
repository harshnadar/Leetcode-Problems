class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n=nums.size();
        if(k==n){
            for(int i=0;i<n-1;i++){
                if(nums[i]!=nums[i+1]) return false;
            }
            return true;
        }
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%k) return false;
        int tar=sum/k;
        vector<int> dp(1<<n,-1);
        dp[0]=0;
        for(int mask=0;mask<(1<<n);mask++){
            if(dp[mask]==-1) continue;
            for(int i=0;i<n;i++){
                if(!(mask&(1<<i)) && (dp[mask]+nums[i])<=tar){
                    dp[mask|(1<<i)]=(dp[mask]+nums[i])%tar;
                }
            }
        }
        return dp[(1<<n)-1]==0;
    }
};