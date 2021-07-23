class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        map<int, int> mp;
        int sum=0;
        mp[0]=1;
        int count=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            count+=mp[sum-k];
            mp[sum]=mp[sum]+1;
        }
        return count;
    }
};