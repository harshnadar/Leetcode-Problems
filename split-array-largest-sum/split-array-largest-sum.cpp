class Solution {
public:
    bool func(int mid, vector<int>& nums, int m){
        int sum=0;
        int n=nums.size();
        int c=1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            if(sum>mid){
                c++;
                sum=nums[i];
                if(c>m) return false;
            }
        }
        return true;
    }
    int splitArray(vector<int>& nums, int m) {
        int n=nums.size();
        int lo= *max_element(nums.begin(), nums.end());
        int hi = 1e9;
        
        while(lo<hi){
            int mid = (lo+hi)/2;
            if(func(mid, nums, m)) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};