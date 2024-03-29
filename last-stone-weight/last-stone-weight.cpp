class Solution {
public:
    int lastStoneWeight(vector<int>& st) {
  multiset<int> s(begin(st), end(st));
  while (s.size() > 1) {
    auto w1 = *prev(s.end());
    s.erase(prev(s.end()));
    auto w2 = *prev(s.end());
    s.erase(prev(s.end()));
    if (w1 - w2 > 0) s.insert(w1 - w2);
  }
  return s.empty() ? 0 : *s.begin();
}
};