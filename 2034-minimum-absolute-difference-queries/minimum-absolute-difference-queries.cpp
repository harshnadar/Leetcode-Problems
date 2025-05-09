class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& qs) {
        vector<int> res, idx[101];
        for (int i = 0; i < nums.size(); ++i)
            idx[nums[i]].push_back(i);
        for (int i = 0; i < qs.size(); ++i) {
            int prev = 0, delta = INT_MAX;
            for (int j = 1; j <= 100; ++j) {
                auto it = lower_bound(begin(idx[j]), end(idx[j]), qs[i][0]);
                if (it != end(idx[j]) && *it <= qs[i][1]) {
                    delta = min(delta, prev == 0 ? INT_MAX : j - prev);
                    prev = j;
                }
            }
            res.push_back(delta == INT_MAX ? -1 : delta);
        }
        return res;
    }
};