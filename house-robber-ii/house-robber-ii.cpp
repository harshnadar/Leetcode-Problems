class Solution {
public:
    int n; int dp[102][2];
    
    int solve(int i, int c, vector<int>& nums){
        if(i>=n) return 0;
        if(dp[i][c]!=-1) return dp[i][c];
        if(i==n-1 && c==1) return 0;
        return dp[i][c]=max(solve(i+1,c,nums), solve(i+2, c, nums)+nums[i]);
    }
    
    int rob(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof dp);
        return max(solve(2,1,nums)+nums[0], solve(1,0, nums));
    }
};