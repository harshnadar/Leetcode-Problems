class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& book, int n) {
        vector<int> res(n);
  for (auto &v : book) {
    res[v[0] - 1] += v[2];
    if (v[1] < n) res[v[1]] -= v[2];
  }
  for (auto i = 1; i < n; ++i) res[i] += res[i - 1];
  return res;
    }
};