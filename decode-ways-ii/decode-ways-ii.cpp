class Solution {
public:
    int numDecodings(string s) {
        int n = s.size(), p = 1000000007;
        // f2 is the answer to sub string ending at position i; Initially i = 0.
        long f1 = 1, f2 = helper(s.substr(0,1));
        // DP to get f2 for sub string ending at position n-1;
        for (int i = 1; i < n; i++) {
            long f3 = (f2*helper(s.substr(i, 1)))+(f1*helper(s.substr(i-1, 2)));
            f1 = f2;
            f2 = f3%p;
        }
        return f2;
    }
private:
    int helper(string s) {
        if (s.size() == 1) {
            if (s[0] == '*') return 9;
            return s[0] == '0'? 0:1;
        }
        // 11-26, except 20 because '*' is 1-9
        if (s == "**")  
            return 15;
        else if (s[1] =='*') {
            if (s[0] =='1') return 9;
            return s[0] == '2'? 6:0;
        }
        else if (s[0] == '*') 
            return s[1] <= '6'? 2:1;
        else 
            // if two digits, it has to be in [10 26]; no leading 0
            return stoi(s) >= 10 && stoi(s) <= 26? 1:0; 
    }
};