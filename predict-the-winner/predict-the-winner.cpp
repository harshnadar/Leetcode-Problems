class Solution {
public:
    int dp[20][20];

    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) dp[i][j]=nums[i];
            }
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if((j-i)==1) dp[i][j]=max(dp[i+1][j], dp[i][j-1]);
                
                if((j-i)>=2){
                    int val1 = nums[i]+min(dp[i+2][j], dp[i+1][j-1]);
                    int val2 = nums[j]+min(dp[i+1][j-1], dp[i][j-2]);
                    
                    dp[i][j]=max(val1, val2);
                }
            }
        }
        
        int sum = accumulate(nums.begin(), nums.end(),0);
        
        return dp[0][n-1]>=(sum-dp[0][n-1]);
    }
};