class Solution {
public:
    int n;
    vector<int> roll_max;
    int MOD = 1e9+7;
    int dp[5002][92];

    int solve(int i, int j){
        if(i>n){
            return 0;
        }
        if(i==n) return 1;

        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;

        for(int u = 1; u<=6; u++){
            if(j>15*(u-1) && j<=15*u){
                if(roll_max[u-1] <= (j - 15*(u-1))) continue;
                ans += solve(i+1, j+1);
                ans%=MOD;
            } 
            else{
                ans+=solve(i+1, 15*(u-1)+1);
                ans%=MOD;
            }
        }
        return dp[i][j] = ans%MOD;
    }

    int dieSimulator(int n, vector<int>& rollMax) {
        this->n = n;
        this->roll_max = rollMax;

        memset(dp,-1,sizeof dp);
        return solve(0, 0);
    }
};