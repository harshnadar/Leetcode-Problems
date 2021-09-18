class Solution {
public:
    bool func(int mid, vector<int>& nums, int k, int m){
        int n=nums.size();
        int bq=0;
        int flowers=0;
        for(int i=0;i<n;i++){
            if(nums[i]>mid){
                flowers=0;
            }
            else{
                bq+=(flowers+1)/k;
                // flowers++;
                flowers=(flowers+1)%k;
            }
        }
        return bq>=m;
    }
    
    int minDays(vector<int>& bloom, int m, int k) {
        int n=bloom.size();
        if(n<m*k) return -1;
        int lo=1;
        int hi=*max_element(begin(bloom), end(bloom));
        
        while(lo<hi){
            int mid=(lo+hi)/2;
            if(func(mid, bloom, k, m)) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};