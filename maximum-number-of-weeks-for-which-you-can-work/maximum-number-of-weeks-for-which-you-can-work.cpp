class Solution {
public:
    long long numberOfWeeks(vector<int>& a) {
        long long int sum=accumulate(a.begin(), a.end(), (long long)0);
        long long int mx=*max_element(a.begin(), a.end());
        long long int ans= min(sum,(long long) 2*(sum-mx)+1);
        return ans;
    }
};