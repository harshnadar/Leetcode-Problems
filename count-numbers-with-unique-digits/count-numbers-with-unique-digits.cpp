class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        long long int dp[10]={0};
        dp[0]=1;
        dp[1] = dp[0]+9;
        long long int ans =1;
        for(int i=2;i<9;i++){
            ans=9;
            for(int j=0;j<i-1;j++){
                ans*=(9-j);
            }
            dp[i]=dp[i-1]+ans;
        }
        return dp[n];
    }
};