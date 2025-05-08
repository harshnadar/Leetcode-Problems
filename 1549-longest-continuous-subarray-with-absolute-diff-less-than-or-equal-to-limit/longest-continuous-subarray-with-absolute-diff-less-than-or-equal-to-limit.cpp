class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int ans=0;
        int i = 0, j=0;
        map<int, int> mp;
        while(j<n && i<n && i<=j){
            mp[nums[j]]++;
            int first_el = mp.begin()->first;
            int last_el = prev(mp.end())->first;
            while(i<j && last_el - first_el > limit){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0) mp.erase(nums[i]);
                first_el = mp.begin()->first;
                last_el = prev(mp.end())->first;
                i++;
            }
            ans = max(ans, j-i+1);
            j++;
        }
        return ans; 
    }
};