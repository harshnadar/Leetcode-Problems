class Solution {
public:
    int n;
    int dp[302][302];

    int longestSubsequence(vector<int>& nums) {
        this->n = nums.size();
        // int ans = 0;
        // ans = 1+solve(nums, 0, 300);
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=300;j++){
                int diff = abs(nums[i] - j);
                dp[nums[i]][diff] = max(dp[nums[i]][diff], dp[j][diff] + 1);
            }

            for(int j=1;j<=300;j++){
                dp[nums[i]][j] = max(dp[nums[i]][j], dp[nums[i]][j-1]);
            }
        }

        int ans = -1e2;
        for(int i=0;i<=300;i++){
            for(int j=0;j<=300;j++){
                ans = max(dp[i][j], ans);
            }
        }

        return ans;
    }
};