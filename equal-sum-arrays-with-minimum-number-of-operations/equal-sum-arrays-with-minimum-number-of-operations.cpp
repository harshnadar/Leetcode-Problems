class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        int s1 =accumulate(nums1.begin(), nums1.end(),0);
        int s2 = accumulate(nums2.begin(), nums2.end(),0);
        if(s1<s2) swap(nums1,nums2);
        int n=nums1.size();
        int m=nums2.size();
        
        if(n*6<m || m*6<n) return -1;
        
        int diff=abs(s1-s2);
        int res=0;
        int cnt[6]={0};
        
        for(auto n: nums1){
            cnt[n-1]++;
        }
        for(auto n: nums2){
            cnt[6-n]++;
        }
        
        for(int i=5;i>0 && diff>0;i--){
            int take = min(cnt[i], diff/i + (diff%i!=0));
            diff-=take*i;
            res+=take;
        }
        return res;
        
    }
};