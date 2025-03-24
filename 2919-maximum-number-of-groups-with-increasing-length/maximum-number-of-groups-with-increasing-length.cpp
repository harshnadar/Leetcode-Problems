class Solution {
public:
    bool satisfy(int groups, vector<int> &usageLimits) {
        int gap = 0;
        int h = groups;
        for (int i = 0; i < usageLimits.size(); ++i) {
            gap = max(h - usageLimits[i] + gap, 0);
            if (h) h -= 1;
        }
        return gap == 0;
    }
    int maxIncreasingGroups(vector<int>& usageLimits) {
        int n = usageLimits.size();
        sort(usageLimits.begin(), usageLimits.end(), greater<int>());
        int l = 1, r = n;
        int res = 1;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (satisfy(mid, usageLimits)) {
                res = max(res, mid);
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
        
    }
};