class Solution {
public:
    map<string, multiset<string> > mp;
    vector<string> ans;

    void dfs(string src){
        cout<<src<<endl;
        while(!mp[src].empty()){
            string tmp = *mp[src].begin();
            mp[src].erase(mp[src].begin());
            dfs(tmp);
        }
        ans.push_back(src);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto it: tickets){
            mp[it[0]].insert(it[1]);
        }
        dfs("JFK");
        reverse(ans.begin(), ans.end());
        return ans;
    }
};