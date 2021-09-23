class Solution {
public:
    int dp[503][503];
    int n;
    vector<int> num;
    
    int solve(int i, int j){
        if(i>=j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int res = 0;
        for(int k=1+i;k<j;k++){
            res = max(res, solve(i,k)+ num[i]*num[j]*num[k] + solve(k,j));
        }
        
        return dp[i][j]=res;
    }
    
    int maxCoins(vector<int>& nums) {
        memset(dp,-1,sizeof dp);
        
        num.push_back(1);
        
        for(auto it: nums) num.push_back(it);
        num.push_back(1);
        
        n=num.size();
        
        return solve(0,n-1);
    }
};