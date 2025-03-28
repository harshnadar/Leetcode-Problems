class Solution {
public:
    vector<vector<string> > ans;
    unordered_map<string, bool> mp;

    bool check(string& s){
        int n = s.size();
        bool flag = true;
        for(int i = 0; i<(n/2 + n%2); i++){
            if(s[i]!=s[n-i-1]){
                flag = false;
                break;
            }
        }
        return mp[s] = flag;
    }

    void solve(int i, string& s, vector<string>& v){
        if(i == s.size()){
            ans.push_back(v);
            return;
        }
        string t = "";

        for(int j = i;j<s.size(); j++){
            t+=s[j];
            if(mp.find(t) != mp.end()){
                if(mp[t]){
                    v.push_back(t);
                    solve(j+1, s, v);
                    v.pop_back();
                }
            }
            else if(check(t)){
                v.push_back(t);
                solve(j+1, s, v);
                v.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> v;
        solve(0,s,v);
        return ans;
    }
};