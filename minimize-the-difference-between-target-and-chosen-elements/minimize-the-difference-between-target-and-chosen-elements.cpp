class Solution {
public:
    vector<vector<int> > dp;
    int n,m;
    vector<set<int> > v;
    
    int solve(int i, int sum, int target){
        if(i>=n) return abs(sum-target);
        
        if(dp[i][sum]!=INT_MAX) return dp[i][sum];
        
        for(auto it: v[i]){
            dp[i][sum] = min(dp[i][sum], solve(i+1, sum+it, target));
            if (dp[i][sum] == 0 || sum + it > target)
                break;
        }
        return dp[i][sum];
    }
    
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        n=mat.size();
        m=mat[0].size();
        dp.resize(72, vector<int>(70*70+2, INT_MAX));
        for(int i=0;i<n;i++){
            v.push_back(set<int>(mat[i].begin(), mat[i].end()));
        }
        return solve(0,0,target);
    }
};