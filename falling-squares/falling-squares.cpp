class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& p) {
        map<pair<int,int>, int> mp;
        mp[{0,1000000000}] = 0;
        vector<int> ans;
        int mx = 0;
        for (auto &v:p) {
            vector<vector<int>> toAdd;
            // cout << endl;
            int len = v[1], a = v[0], b =v[0] + v[1], h = 0;
            auto it = mp.upper_bound({a,b});
            if (it != mp.begin() && (--it)->first.second <= a) ++it;
            while (it != mp.end() && it->first.first <b) {
                if (a > it->first.first) toAdd.push_back({it->first.first,a,it->second});
                if (b < it->first.second) toAdd.push_back({b,it->first.second,it->second});
                h = max(h, it->second);
                it = mp.erase(it);
            }
            mp[{a,b}] = h + len;
            for (auto &t:toAdd) mp[{t[0],t[1]}] = t[2];
            mx = max(mx, h + len);
            ans.push_back(mx);
        }
        
        return ans;
    }
};