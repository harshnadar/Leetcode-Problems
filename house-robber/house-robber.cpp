class Solution {
public:
    int dp[103];
    int n;
    
    int solve(int i, vector<int>& nums){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        return dp[i]=max(solve(i+1,nums), solve(i+2, nums)+nums[i]);
        // return dp[i]=tmp_ans;
    }
    
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        n=nums.size();
        return solve(0, nums);
    }
};