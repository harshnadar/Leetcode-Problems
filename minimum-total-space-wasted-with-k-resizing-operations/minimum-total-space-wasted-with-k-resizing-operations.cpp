class Solution {
public:
    int dp[201][201];
    int n;
    
    int dfs(vector<int>& nums, int i, int k){
        if(i>=n) return 0;
        if(k==-1) return 2*1e8;
        if(dp[i][k]!=-1) return dp[i][k];
        int mx=nums[i];
        int res=2*1e8;
        int totSum=0;
        for(int j=i;j<n;j++){
            mx=max(mx, nums[j]);
            totSum+=nums[j];
            int wasted = mx*(j-i+1)-totSum;
            res=min(res, dfs(nums, j+1, k-1)+wasted);
        }
        return dp[i][k]=res;
    }
    
    int minSpaceWastedKResizing(vector<int>& nums, int k) {
        n=nums.size();
        memset(dp,-1,sizeof dp);
        return dfs(nums,0, k);
    }
};