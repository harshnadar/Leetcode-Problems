class Solution {
public:
    bool func(int mid, vector<int>& nums, int h){
        // int sum=0;
        int hour=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            hour+=(nums[i]/mid) + ((nums[i]%mid)>0);
            if(hour>h) return false;
        }
        return true;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int lo=1;
        int hi=1e9;
        while(lo<hi){
            int mid= (lo+hi)/2;
            if(func(mid, piles, h)) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};