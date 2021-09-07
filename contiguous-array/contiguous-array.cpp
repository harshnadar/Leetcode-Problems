class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0) nums[i]=-1;
        }
        map<int, int> mp;
        int sum=0;
        int ans=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum == 0) ans=i+1;
            if(mp.find(sum)!=mp.end()) ans=max(i-mp[(sum)],ans);
            else mp[sum] = i;
        }
        return ans;
    }
};