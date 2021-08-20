class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return vector<int>();
        if(n==1) return nums;
        vector<int> dp(n+1,1);
        int mx=INT_MIN;
        sort(nums.begin(), nums.end());
        
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[i]%nums[j]==0)
                    if(dp[j]+1 > dp[i]) dp[i]=1+dp[j];
            }
            if(dp[i]>mx) mx=dp[i];
        }
        vector<int> ans;
        int prev=0;
        for(int i=n-1;i>=0;i--){
            if(dp[i]==mx && prev%nums[i]==0){
                ans.push_back(nums[i]);
                mx--;
                prev=nums[i];
            }
        }
        return ans;
    }
};