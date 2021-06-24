class Solution {
public:
    int dp[52][52][52];
    const int mod=1e9+7;
    
    long long int func(int n, int m, int N, int i, int j){
        if(N<0) return 0;
        if(i==-1 || j==-1 || i==n || j==m) return 1;
        if(dp[i][j][N]!=-1) return dp[i][j][N];
        long long int a= func(n,m,N-1,i-1,j);
        long long int b=func(n,m,N-1,i+1,j);
        long long int c=func(n,m,N-1,i,j-1);
        long long int d=func(n,m,N-1,i,j+1);
        long long int total =(a+b+c+d)%mod;
        return dp[i][j][N]=total;
    }
    
    int findPaths(int n, int m, int mm, int sr, int sc) {
        memset(dp,-1,sizeof dp);
        return func(n,m,mm,sr,sc);
    }
};