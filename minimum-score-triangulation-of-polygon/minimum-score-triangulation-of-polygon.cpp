class Solution {
public:
    int dp[51][51];
    int n;
    vector<int> values;
    
    int solve(int i, int j){
        if(i+1>=j) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int res = 1e8;
        for(int k=1+i;k<j;k++){
            res = min(res, solve(i,k)+ values[i]*values[j]*values[k] + solve(k,j));
        }
        
        return dp[i][j]=res;
    }
    
    int minScoreTriangulation(vector<int>& values) {
        memset(dp,-1,sizeof dp);
        n=values.size();
        
        this->values=values;
        return solve(0,n-1);
    }
};