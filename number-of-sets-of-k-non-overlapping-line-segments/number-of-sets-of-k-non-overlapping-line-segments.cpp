class Solution {
public:
    int numberOfSets(int n, int m) {
        vector<vector<long long int> > dp(n+1,vector<long long int>(m+1,0));
        vector<vector<long long int> > prev(n+1,vector<long long int>(m+1,0));
        int mod= 1e9+7;
        for(int i=2;i<n+1;i++){
            for(int j=1;j<=m;j++){
                if(j>=i) break;
                if(i==j+1){
                    prev[i][j]=prev[i-1][j]+1;
                    dp[i][j]=1;
                    continue;
                }
                if(j==1){
                    dp[i][j]=(((i)*(i-1))/2)%mod;
                    prev[i][j]=(prev[i-1][j]+ dp[i][j])%mod;
                    continue;
                }
                dp[i][j] = (prev[i-1][j-1] + dp[i-1][j])%mod;
                prev[i][j]=prev[i-1][j]+dp[i][j];
                prev[i][j]%=mod;
            }
        }
        // for(int i=2;i<n+1;i++){
        //     for(int j=1;j<=m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[n][m];
    }
};