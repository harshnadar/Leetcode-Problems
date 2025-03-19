class Solution {
public:
    int n;
    int dp[1002][1002];

    int solve(vector<vector<int>>& queries, int i, int num, int idx){
        if(num<0) return 1e7;
        if(num == 0) return 0;
        if(i>=n) return 1e7;

        if(dp[i][num]!=-1) return dp[i][num];

        int a = 1e7;

        if(queries[i][0]<=idx && queries[i][1]>=idx){
            a = min(a, 1+solve(queries, i+1, num-queries[i][2], idx));
            a = min(a, 1+solve(queries, i+1, num, idx));
        }
        else{
            a = min(a, 1+solve(queries, i+1, num, idx));
        }
        return dp[i][num] = a;
    }
    
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        this->n = queries.size();
        int ans = -1;

        for(int i=0;i<nums.size(); i++){
            memset(dp,-1,sizeof dp);
            ans = max(ans, solve(queries, 0, nums[i], i));
        }
        if(ans>=1e7) return -1;
        return ans;

    }
};