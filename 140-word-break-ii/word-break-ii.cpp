class Solution {
public:
    vector<string> ans;
    map<string, int> mp;

    void solve(string& s, int i, string temp){
        if(i>=s.size()){
            ans.push_back(temp);
        }
        string u = temp;
        for(int j = i; j<s.size(); j++){
            string a = s.substr(i, j-i+1);
            if(mp.find(a)!=mp.end()){
                
                if(temp.size() == 0) temp+=a;
                else temp+=" " + a;
                solve(s, j+1, temp);
                temp = u;
            }
        }
        return;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        for(auto it: wordDict) mp[it]++;
        string temp = "";
        solve(s, 0, temp);
        return ans;
    }
};