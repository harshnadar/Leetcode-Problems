class Solution {
public:
    void remove(string s, vector<string>& ans, int last_i, int last_j, string par){
        for(int stack=0, i =last_i;i<s.size();i++){
            if (s[i] == par[0]) stack++;
            if (s[i] == par[1]) stack--;
            if (stack >= 0) continue;
            for (int j = last_j; j <= i; ++j)
                if (s[j] == par[1] && (j == last_j || s[j - 1] != par[1]))
                    remove(s.substr(0, j) + s.substr(j + 1, s.size()), ans, i, j, par);
            return;
        }
        string rev = s;
        reverse(begin(rev), end(rev));
        if(par[0]=='('){
            remove(rev,ans,0,0,")(");
        }
        else ans.push_back(rev);
    }
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        remove(s,ans,0,0,"()");
        return ans;
    }
    
};