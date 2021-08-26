class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> pref(n), suf(n);
        for(int i=0;i<n;i++){
            pref[i]=1;
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    pref[i]=max(pref[i], pref[j]+1);
                }
            }
        }
        
        for(int i=n-1;i>=0;i--){
            suf[i]=1;
            for(int j=n-1;j>i;j--){
                if(nums[i]>nums[j]){
                    suf[i]=max(suf[i], suf[j]+1);
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(pref[i]>1 && suf[i]>1){
                ans = max(pref[i]+suf[i]-1, ans);
            }
        }
        return n-ans;
    }
};