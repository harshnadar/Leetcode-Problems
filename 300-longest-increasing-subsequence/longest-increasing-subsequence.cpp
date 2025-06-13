class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> s;
        int ans = 0;
        for(int a: nums){
            auto it = lower_bound(s.begin(), s.end(), a) - s.begin();
            if(s.empty() || s.back() < a){
                s.push_back(a);
            }
            if(it < s.size()){
                s[it] = a;
            }
            if(!s.empty())
                ans = max(ans, (int)s.size());
        }
        return ans;
    }
};