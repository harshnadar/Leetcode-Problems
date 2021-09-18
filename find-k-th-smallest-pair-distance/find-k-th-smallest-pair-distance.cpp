class Solution {
public:
    bool func(int mid,vector<int>& nums, int k){
        int n=nums.size();
        int i=0,j=0;
        int count=0;
        while(i<n || j<n){
            while(j<n && nums[j]-nums[i]<=mid){
                j++;
            }
            count+=j-i-1;
            i++;
        }
        return count>=k;        
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(begin(nums), end(nums));
        int n=nums.size();
        int lo=0, hi=nums[n-1]-nums[0];
        
        while(lo<hi){
            int mid=(lo+hi)/2;
            
            if(func(mid,nums,k)) hi=mid;
            else lo=mid+1;
        }
        return lo;
    }
};