class Solution {
public:
    int n;
    int dp[502][502];
    int presum[502];
    // vector<int>
    
    int solve(int left, int right){
        if(left>=right) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        
        int res=0;
        
        for(int t=left;t<right;t++){
            if(presum[t+1]-presum[left] > presum[right+1]-presum[t+1]){
                res = max(res, presum[right+1]-presum[t+1] + solve(t+1, right));
            }
            else if(presum[t+1]-presum[left] < presum[right+1]-presum[t+1]){
                res = max(res, presum[t+1]-presum[left]+solve(left, t));
            }
            else{
                res = max({res, presum[t+1]-presum[left]+solve(left, t), presum[right+1]-presum[t+1] + solve(t+1, right)});
            }
        }
        
        return dp[left][right] = res;
    }
    
    int stoneGameV(vector<int>& stones) {
        n=stones.size();
        // this->stones = stones;
        
        for(int i=1;i<n+1;i++){
            presum[i]=presum[i-1]+stones[i-1];
        }
        
        memset(dp,-1,sizeof dp);
        
        return solve(0,n-1);
    }
};