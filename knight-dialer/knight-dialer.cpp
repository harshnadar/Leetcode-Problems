int dx[]={1,2,2,1,-1,-2,-2,-1};
int dy[]={-2,-1,1,2,2,1,-1,-2};
class Solution {
public:
    int dp[4][3][5001];
    const int mod= 1e9+7;
    
    int solve(int i, int j, int n){
        if(i<0 || i>=4 || j<0 || j>=3) return 0;
        if(i==3 && (j==0 || j==2)) return 0;
        if(n==1) return 1;
        if(dp[i][j][n]>0) return dp[i][j][n];
        long long int res=0;
        for(int k=0;k<8;k++){
            res+=solve(i+dx[k], j+dy[k], n-1);
            res%=mod;
        }
        return dp[i][j][n]=res;
    }
    
    int knightDialer(int n) {
        // if(n==1) return 10;
        long long int count=0;
        for(int i=0;i<4;i++){
            for(int j=0;j<3;j++){
                count+=solve(i,j,n);
                count%=mod;
            }
        }
        return (int)count;
    }
};