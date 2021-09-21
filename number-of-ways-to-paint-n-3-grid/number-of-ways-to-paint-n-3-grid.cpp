#define FAST_IO ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
class Solution {
public:
    int MOD = 1e9 + 7;
    string moves[12] = {
        "123",
        "132",
        "121",
        "131",
        "213",
        "231",
        "232",
        "212",
        "312",
        "321",
        "313",
        "323",
    };
    vector<vector<int>>memo;
    int solve(int n, int lastIdx) {
        if (n == 0) return 1;
        int ret = 0;
        if (memo[n][lastIdx] != -1) return memo[n][lastIdx];
        string last = moves[lastIdx];
        for (int idx = 0; idx <12; idx++) {
            string move = moves[idx];
            bool same = false;
            for (int i = 0; i < 3; i++) if (move[i] == last[i]) same = true;
            if (!same) ret = (ret + solve(n - 1, idx)%MOD)%MOD;
        }
        return memo[n][lastIdx]= ret%MOD;
    }
    int numOfWays(int n) {
       memo.resize(n + 1, vector<int>(12, -1));
        int ret = 0;
        for (int idx = 0; idx < 12; idx++)
            ret =  (ret + solve(n-1, idx)%MOD)%MOD;
        return ret;
    }
};