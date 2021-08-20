class Solution {
public:
    int dp[20002];
    int t[20002];
    int n;

    
    int maxProduct(vector<int>& nums) {
        n=nums.size();
        dp[0]=nums[0];
        t[0]=nums[0];
        for(int i=1;i<n;i++){
            dp[i]=max({nums[i], dp[i-1]*nums[i], t[i-1]*nums[i]});
            t[i]=min({nums[i], dp[i-1]*nums[i], t[i-1]*nums[i]});
        }
        
        return *max_element(dp,dp+n);
    }
};