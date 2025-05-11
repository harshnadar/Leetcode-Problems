class Solution {
public:
    bool check(string& s1, string& s2){
        int n = s1.size(), m = s2.size();
        if(n-m != 1) return false;
        bool flag = false;
        for(int i=0;i<m;i++){
            if(flag){
                if(s1[i+1] != s2[i]) return false;
            }
            else{
                if(s1[i]!=s2[i]){
                    flag = true;
                    i--;
                }
            }
        }
        return true;
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();
        map<int, vector<string>> mp;
        set<string> se;
        int ans = 1;
        map<string, int> dp;
        for(auto it: words){
            if(se.find(it)!=se.end()) continue;
            se.insert(it); 
            dp[it] = 1;
            mp[it.size()].push_back(it);
        }
        int max_len = prev(mp.end())->first;
        
        for(int i = max_len; i>=2; i--){
            for(auto s1: mp[i]){
                for(auto s2: mp[i-1]){
                    if(check(s1, s2)) dp[s2] = max(dp[s2], dp[s1] + 1);
                    ans = max(ans, dp[s2]);
                }
            }
        }
        return ans;
    }
};