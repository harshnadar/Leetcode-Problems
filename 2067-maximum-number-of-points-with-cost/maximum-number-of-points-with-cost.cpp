class Solution {
public:
    // vector<vector<long long int> > dp;
    // int n, m;
    // long long int solve(vector<vector<int> >& nums, int i, int j){
    //     if(i>=n) return 0;
    //     if(dp[i][j]!=-1) return dp[i][j];
    //     long long temp = INT_MIN;
    //     for(int k = 0; k<m;k++){
    //         temp = max(temp, (long long)nums[i][k] - (long long)abs(k-j) + solve(nums, i+1, k));
    //     }
    //     return dp[i][j] = temp;
    // }

    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int m = points[0].size();
        vector<long long> dp(points[0].begin(), points[0].end());
        for(int i=1;i<n;i++){
            vector<long long> new_dp(m, 0);
            long long left_max = INT_MIN;
            for(int j=0;j<m;j++){
                left_max = max(left_max - 1, dp[j]);
                new_dp[j] = max(new_dp[j], left_max + points[i][j]);
            }
            long long right_max = INT_MIN;
            for(int j = m-1;j>=0;j--){
                right_max = max(right_max - 1, dp[j]);
                new_dp[j] = max(new_dp[j], right_max + points[i][j]);
            }

            dp = new_dp;
        }
        return *max_element(dp.begin(), dp.end());
    }
};