class Solution {
public:
    int maxCoins(vector<int>& a) {
        int n=a.size();
        if(n==0) return 0;
        int dp[n+1][n+1];
        memset(dp,0,sizeof dp);
        for(int L=n-1;L>=0;L--){
            for(int R=L;R<n;R++){
                for(int i=L;i<=R;i++){
                    dp[L][R]=max(dp[L][R], 
                                 a[i]*(L?a[L-1]:1)*((R==n-1)?1:a[R+1]) + (L<=i-1?dp[L][i-1]:0)+ (R>=i+1?dp[i+1][R]:0));
                }
            }
        }
        return dp[0][n-1];
    }
};