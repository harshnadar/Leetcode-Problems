class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        int n=nums.size();
        int cnt=0;
        int ans=0;
        for(int i=2;i<n;i++)
        {
           if(nums[i]-nums[i-1]==nums[i-1]-nums[i-2])
               cnt++;
            else{
                ans+=(cnt*(cnt+1)/2);
                cnt=0;
            }
        }
        return ans+(cnt*(cnt+1)/2);
    }
};