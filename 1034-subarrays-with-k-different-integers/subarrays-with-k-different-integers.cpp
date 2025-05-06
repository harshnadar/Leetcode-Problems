class Solution {
public:
    int solve(vector<int>& nums, int k){
        if(k==0) return 0;
        map<int, int> mp;
        int i = 0, j=0;
        int n = nums.size();
        int count = 0;
        while(i<n && j<n && i<=j){
            mp[nums[j]]++;
            if(mp.size() > k){
                while(i<j && mp.size()>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0) mp.erase(nums[i]);
                    i++;
                }
            }
            count+=j-i+1;
            j++;
        }

        return count;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};