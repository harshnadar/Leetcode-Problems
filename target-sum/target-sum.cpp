class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=accumulate(nums.begin(), nums.end(),0);
        if((sum+target)%2 || target>sum || target<-sum) return 0;
        int s = (target+sum)/2;
        int n=nums.size();
        int dp[s+1];
        memset(dp,0,sizeof dp);
        dp[0]=1;
        for(int i=0;i<n;i++){
            // dp[nums[i]]++;
            for(int j=s;j>=nums[i];j--){
                if(j-nums[i] >=0){
                    dp[j]+= dp[j-nums[i]];
                }
            }
        }
        return dp[s];
    }
};