class Solution {
public:
    bool check(int x, vector<int>& a, int k){
        int n=a.size();
        int sum=0;
        for(int i=0;i<n;i++){
            sum+=(a[i]/x + (a[i]%x >0));
        }
        return sum>k;
    }
    
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int lo=1;
        int hi=*max_element(nums.begin(), nums.end());
        int ans=hi;
        // cout<<check(3,nums,threshold);
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(mid, nums, threshold))  lo=mid+1;
            else  ans=mid, hi=mid-1;
        }
        return ans;
    }
};