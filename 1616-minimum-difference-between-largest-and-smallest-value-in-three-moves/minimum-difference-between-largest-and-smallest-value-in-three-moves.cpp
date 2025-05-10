class Solution {
public:
    // long long int solve(vector<int>nums, int val){
    //     int count = 0;
    //     int i = 0, j = nums.size()-1;
    //     while(count<3){
    //         if(i>=j){
    //             break;
    //         }
    //         if(val - nums[i] > nums[j] - val){
    //             i++;
    //         }
    //         else if (val - nums[i] < nums[j] - val){
    //             j--;
    //         }
    //         else{
                
    //         }
    //         count++;
    //     }
    //     return nums[j] - nums[i];
    // }
    int minDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int k = 3;
        if(n<=k+1) return 0;
        long long ans = INT_MAX;
        for(int i=0;i<=k;i++){
            ans = min(ans, (long long)nums[n-k-1+i] - nums[i]);
        }
        return ans;
    }
};