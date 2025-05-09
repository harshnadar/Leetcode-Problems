class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        int l = 0, r=0, ans = INT_MAX;
        int curr_sum = 0;
        vector<int> dp(n, INT_MAX);

        for(int r = 0;r<n;r++){
            curr_sum +=arr[r];
            while(curr_sum > target){
                curr_sum -=arr[l];
                l++;
            }
            if(curr_sum == target){
                dp[r] = r-l+1;
                if(l-1 >=0 && dp[l-1]!=INT_MAX){
                    ans = min(ans, dp[r] + dp[l-1]);
                }
            }
            if(r-1>=0){
                dp[r] = min(dp[r-1], dp[r]);
            }
        }
        return (ans == INT_MAX)?-1:ans;
    }
};