class Solution {
public:
    int dp[1002];
    int n;
    
    int solve(int i, vector<vector<int>>& pairs){
        if(i>=n) return 0;
        int j=0;
        if(dp[i]!=-1) return dp[i];
        
        for(j=i+1;j<n;j++){
            if(pairs[i][1]<pairs[j][0]) break;
        }
        
        return dp[i] = max(solve(i+1, pairs), 1+solve(j, pairs));
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(), pairs.end());
        n=pairs.size();
        memset(dp,-1,sizeof dp);
        return solve(0, pairs);
    }
};