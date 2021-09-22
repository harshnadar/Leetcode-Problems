class Solution {
public:
    int dp[101][21][101];
    vector<vector<int> > cost; int n,m;
    vector<int> houses;
    
    int solve(int i, int last, int target){
        if(i>=m || target<0){
            return (target==0)?target:1e8;
        }
        if(dp[i][last][target]!=-1) return dp[i][last][target];
        
        if(houses[i]!=0){
            return solve(i+1,houses[i], target - (houses[i]!=last));
        }
        int res = 1e8;
        
        for(int j=0;j<n;j++){
            res = min(res, cost[i][j] + solve(i+1,j+1, target - (last!=j+1)));
        }
        
        return dp[i][last][target] = res;
        
    }
    
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        this->n = n;
        this->m = m;
        
        memset(dp,-1,sizeof dp);
        
        this->cost = cost;
        this->houses = houses;
        
        int ans=solve(0,0,target);
        
        return (ans>=1e8)?-1:ans;
    }
};