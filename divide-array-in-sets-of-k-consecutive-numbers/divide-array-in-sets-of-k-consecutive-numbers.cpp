class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        if(n%k) return false;
        for(auto it: mp){
            if(it.second){
                int freq=it.second;
                for(int i=0;i<k;i++){
                    if(mp[it.first+i]< freq) return false;
                    else mp[it.first+i]-=freq;
                }
            }
        }
        return true;
    }
};