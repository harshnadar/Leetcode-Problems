class Solution {
public:
    int solve(vector<int>& slices, int l, int r){
        int n=slices.size();
        int dp[n+1][n/3+1];
        memset(dp,0,sizeof dp);
        
        for(int i=l;i<=r;i++){
            for(int j=0;j<n/3;j++){
                dp[i][j]=max(((i>=1)?dp[i-1][j]:0), ((i>=2 && j>=1)?dp[i-2][j-1]:0)+slices[i]);
            }
        }
        return dp[r][n/3 -1];
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        
        return max(solve(slices,0,n-2), solve(slices,1,n-1));
    }
};