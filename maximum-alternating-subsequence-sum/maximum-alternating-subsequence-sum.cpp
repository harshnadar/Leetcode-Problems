#define intl long long
#define f(a,b,i) for(int i=a;i<b;i++)

class Solution {
public:
    intl maxAlternatingSum(vector<int>& nums) {
        intl n=nums.size();
        intl dp[n][2];
        memset(dp,0,sizeof(dp));
        dp[0][0]=nums[0];
        dp[0][1]=0;
        f(1,n,i)
        {
            dp[i][0]=max(dp[i-1][1]+nums[i],dp[i-1][0]);
            dp[i][1]=max(dp[i-1][0]-nums[i], dp[i-1][1]);
        }
        return max(dp[n-1][0],dp[n-1][1]);
    }
};