class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int i=k,j=k;
        int mn = nums[i];
        int res=mn;
        int n=nums.size();
        
        while(i>0 || j<n-1){
            if(((i>0)?nums[i-1]:0)<((j<n-1)?nums[j+1]:0)){
                mn=min(mn,nums[j+1]);
                j++;
            }
            else{
                mn=min(mn, nums[i-1]);
                i--;
            }
            res = max(res,mn*(j-i+1));
        }
        return res;
    }
};