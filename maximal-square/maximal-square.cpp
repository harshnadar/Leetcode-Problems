class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n=mat.size(), m=mat[0].size();
        if(mat.empty()) return 0;
        int dp[n][m];
        memset(dp,0,sizeof dp); int sz=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!i || !j || mat[i][j]=='0') dp[i][j]=mat[i][j]-'0';
                else dp[i][j]=min({dp[i][j-1], dp[i-1][j-1], dp[i-1][j]})+1;
                sz=max(dp[i][j],sz);
            }
            
        }
        return sz*sz;
    }
};