int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={-2,-1,1,2,2,1,-1,-2};

class Solution {
public:
    int dp[5002][4][3];
    int mod = 1e9+7;
    
    int solve(int i, int j, int n){
        if(n<0 || i<0 || i>=4 || j<0 || j>=3) return 0;
        if(i==3&&(j==0 || j==2)) return 0;
        if(dp[n][i][j]!=-1) return dp[n][i][j];
        long long int temp=0;
        for(int k=0;k<8;k++){
            temp+=solve(i+dx[k], j+dy[k], n-1);
            temp%=mod;
        }
        return dp[n][i][j]=temp;
    }
    
    int knightDialer(int n) {
        memset(dp,-1,sizeof dp);
        if(n==1) return 10;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++)
                if(!(i==3&&(j==0 || j==2))) dp[0][i][j]=1;
        }
        long long int x=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                x+=solve(i,j,n-1);
                x%=mod;
            }
        }
        return x;
    }
};