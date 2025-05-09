class Solution {
public:
    int dp[2002][2002];

    bool solve(string& s, string& p, int i, int j){
        if(i == s.size() && j == p.size()) return true;
        else if(i>s.size() || j>p.size()) return false;
        if(dp[i][j]!=-1) return dp[i][j];

        bool a = false;
        if(p[j] == '*'){
            a = a || solve(s, p, i+1, j);
            if(a) return a;
            a = a || solve(s, p, i+1, j+1);
            if(a) return a;
            a = a || solve(s, p, i, j+1); 
            if(a) return a;
        }
        else if(p[j] == '?'){
            a = a || solve(s, p, i+1, j+1);
            if(a) return a;
        }
        else{
            if(s[i] == p[j]){
                a = a || solve(s, p, i+1, j+1);
                if(a) return a;
            }
            else{
                return false;
            }
        }

        return dp[i][j] = a;
    }
    bool isMatch(string s, string p) {
        memset(dp,-1,sizeof dp);
        return solve(s, p, 0, 0);

    }
};