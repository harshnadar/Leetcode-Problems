class Solution {
public:
    int n,m;
    
    int solve(vector<vector<int> >& mat, vector<vector<int> >& dp, int i, int j){
        if(i==n || j==m) return 1e6+5;
        if(i==n-1 && j==m-1) return ((mat[i][j]<0)?(-mat[i][j]+1):1);
        if(dp[i][j]<1e6+5) return dp[i][j];
        int right= solve(mat, dp, i,j+1);
        int down = solve(mat, dp, i+1, j);
        int ans= min(right, down)-mat[i][j];
        return dp[i][j]=((ans<=0)?1:ans);
        
    }
    
    int calculateMinimumHP(vector<vector<int>>& mat) {
        n=mat.size();
        m=mat[0].size();
        vector<vector<int> > dp(n,vector<int>(m,1e6+5));
        return solve(mat, dp, 0,0);
    }
};