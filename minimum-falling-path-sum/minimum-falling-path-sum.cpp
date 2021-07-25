class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                int x=mat[i][j]+((j-1>=0)?mat[i-1][j-1]:1e6);
                int y=mat[i][j]+((j+1<m)?mat[i-1][j+1]:1e6);
                int z=mat[i][j]+mat[i-1][j];
                mat[i][j]=min({x,y,z});
            }
        }
        int ans=1e6;
        for(int i=0;i<m;i++){
            ans=min(ans, mat[n-1][i]);
        }
        return ans;
    }
};