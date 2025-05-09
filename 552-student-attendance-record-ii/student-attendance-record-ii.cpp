class Solution {
public:
    int dp[100002][3][4];
    int n;
    int MOD = 1e9+7;

    int solve(int i, int abs_count, int consec_late_count){
        if(i>=n) return 1;
        if(dp[i][abs_count][consec_late_count]!=-1) return dp[i][abs_count][consec_late_count];

        int a = 0, b = 0, c = 0;
        if(abs_count==0){
            a = solve(i+1, abs_count+1, 0);
            a%=MOD;
        }
        if(consec_late_count<2){
            b = solve(i+1, abs_count, consec_late_count+1);
            b%=MOD;
        }
        c = solve(i+1, abs_count, 0);
        c%=MOD;

        return dp[i][abs_count][consec_late_count] = ((a+b)%MOD + c)%MOD;
    }

    int checkRecord(int n) {
        this->n = n;
        memset(dp,-1,sizeof dp);
        return solve(0, 0,0);
    }
};