class Solution {
public:
    int dp[501][501];
    int n;
    
    vector<int> s;
    
    int solve(int i, int k){
        if(i>=n || k>n) return 0;
        if(dp[i][k]!=-1) return dp[i][k];
        
        return dp[i][k]=max(solve(i+1,k), solve(i+1,k+1) + k*s[i]);
    }
    int maxSatisfaction(vector<int>& sat) {
        n=sat.size();
        sort(sat.begin(), sat.end());
        this->s = sat;
        memset(dp,-1,sizeof dp);
        
        int ans =solve(0,1);
        // for(int i=0;i<n;i++) cout<<dp[i]<<' ';
        return ans;
    }
};