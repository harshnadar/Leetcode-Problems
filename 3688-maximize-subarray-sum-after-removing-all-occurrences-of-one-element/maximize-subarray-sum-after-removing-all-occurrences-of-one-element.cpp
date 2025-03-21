class Solution {
public:
    long long maxSubarraySum(vector<int>& nums) {
        map<long long int, long long int> min_pref;
        long long int low = 0;
        long long int prefix_sum = 0;
        long long int ans = nums[0];
        min_pref[0]=0;

        for(auto n: nums){
            prefix_sum +=n;
            ans = max(ans, prefix_sum - low);
            if(n<0){
                if(min_pref.find(n)!=min_pref.end()){
                    min_pref[n] = min(min_pref[n], min_pref[0]) + n;
                }
                else{
                    min_pref[n] = min_pref[0] + n;
                }
                low = min(low, min_pref[n]);
            }
            min_pref[0] = min(min_pref[0], prefix_sum);
            low = min(low, min_pref[0]);

        }
        return ans;
    }
};