class Solution {
public:
    int dp[201][201];
    int n,m;
    
    int dfs(int i, int j, int prev, vector<vector<int>>& matrix){
        if(i<0 || i>=n || j<0 || j>=m || matrix[i][j]<prev) return 0;
        
        if(matrix[i][j]>prev){
            if(dp[i][j]!=-1) return dp[i][j];
            int a = 1+dfs(i+1,j,matrix[i][j],matrix);
            int b= 1+dfs(i-1,j,matrix[i][j], matrix);
            int c= dfs(i,j-1,matrix[i][j], matrix)+1;
            int d= dfs(i,j+1, matrix[i][j], matrix)+1;
            return dp[i][j]=max({a,b,c,d});
        }
        return 0;
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        memset(dp,-1,sizeof dp);
        n=matrix.size();
        m=matrix[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans=max(ans, dfs(i,j,-1,matrix));
            }
        }
        return ans;
    }
};