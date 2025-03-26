class Solution {
public:
    int dp[10000002];
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        // int n = nums.size();
        // int max_el = *max_element(nums.begin(), nums.end());
        // int block_size = ceil(sqrt(max_el));
        // cout<<block_size<<endl;
        // vector<int> max_array(block_size+1,0);
        
        // vector<int> ans;
        // for(int i=0;i<n;i++){
        //     int curr_block = nums[i]/block_size;
        //     int curr_block_idx = nums[i]%block_size;
        //     cout<<i<<" "<<nums[i]<<" "<<curr_block<<" "<<curr_block_idx<<endl;
        //     int a = 0, b=0;
        //     for(int j = 0;j<curr_block;j++){
        //         b = max(b, max_array[j]);
        //     }
        //     for(int j=0;j<=curr_block_idx;j++){
        //         a = max(a, dp[block_size*curr_block + j]);
        //     }
        //     dp[nums[i]] = max(a,b)+1;
        //     for(int j=0;j<=curr_block_idx;j++){
        //         max_array[curr_block] = max(max_array[curr_block], dp[nums[i]]);
        //     }
        //     ans.push_back(dp[nums[i]]);

        // }
        // return ans;
        vector<int> lis;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(lis.empty() || lis[lis.size()-1] <=x){
                lis.push_back(x);
                nums[i] = lis.size();
            }
            else{
                int idx = upper_bound(lis.begin(), lis.end(), x) - lis.begin();
                cout<<idx<<endl;
                lis[idx] = x;
                nums[i] = idx+1;
            }
        }
        return nums;
    }
};