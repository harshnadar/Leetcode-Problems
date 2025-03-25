class Solution {
public:
    
    int lengthOfLIS(vector<int>& nums, int k) {
        int n = nums.size();
        int max_el = *max_element(nums.begin(), nums.end());
        int block_size = ceil(sqrt(max_el));
        int num_blocks = block_size;

        int dp[318][318] = {0};

        for(int i=0;i<n;i++){
            if(i && nums[i] == nums[i-1]) continue;

            int left = max(0,nums[i] - k), right = nums[i]-1;

            int right_block = right/block_size;
            int right_block_idx = right%block_size;

            int left_block = left/block_size;
            int left_block_idx = left%block_size;

            int curr_block = nums[i]/block_size;
            int curr_block_idx = nums[i]%block_size;

            if(left_block == right_block){
                for(int j = right_block_idx;j>=left_block_idx;j--){
                    dp[curr_block][curr_block_idx] = max(dp[curr_block][curr_block_idx], 1+dp[left_block][j]);
                }
            }
            else{
                for(int j=right_block_idx;j>=0;j--){
                    dp[curr_block][curr_block_idx] = max(dp[curr_block][curr_block_idx], 1+dp[right_block][j]);
                }

                for(int j=right_block-1;j>left_block;j--){
                    dp[curr_block][curr_block_idx] = max(dp[curr_block][curr_block_idx], 1+dp[j][block_size]);
                }
                
                for(int j=block_size-1;j>=left_block_idx;j--){
                    dp[curr_block][curr_block_idx] = max(dp[curr_block][curr_block_idx], 1+dp[left_block][j]);
                }
            }

            dp[curr_block][block_size] = max(dp[curr_block][block_size], dp[curr_block][curr_block_idx]);
        }

        int ans = 0;
        for(int i=0;i<=block_size;i++){
            ans = max(ans, dp[i][block_size]);
        }
        return ans;

    }
};

