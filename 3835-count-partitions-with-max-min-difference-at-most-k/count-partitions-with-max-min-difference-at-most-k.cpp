class Solution {
public:
    int MOD = 1e9+7;

    int countPartitions(vector<int>& nums, int k) {
        int n = nums.size();
        int acc = 1;
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        deque<int> maxq, minq;
        for(int i=0,j=0;j<n;j++){
            while(!maxq.empty() && nums[j] > nums[maxq.back()]){
                maxq.pop_back();
            }
            maxq.push_back(j);
            while(!minq.empty() && nums[j] < nums[minq.back()]){
                minq.pop_back();
            }
            minq.push_back(j);
            while(nums[maxq.front()] - nums[minq.front()] > k){
                acc = (acc-dp[i++] + MOD)%MOD;
                if(minq.front() < i) minq.pop_front();
                if(maxq.front() < i) maxq.pop_front();
            }

            dp[j+1] = acc;
            acc = (acc+dp[j+1])%MOD;
        }
        return dp[n];
    }
};