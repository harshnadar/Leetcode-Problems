class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int min_len = INT_MAX;
        if(accumulate(nums.begin(), nums.end(), 0) < target) return 0;
        int i=0,j=0;
        int sum=0;
        while(j<n){
            sum+=nums[j];
            if(sum<target){
                j++;
                continue;
            }
            else{
                while(sum>=target){
                    sum-=nums[i];
                    i++;
                }
                j++;
                min_len = min(min_len, j-i+1);
            }
        }
        return min_len;
    }
};