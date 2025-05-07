class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        map<string, int> check;
        vector<vector<int> > ans;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i] == nums[i-1]) continue;
            int curr_num = nums[i];
            int j = i+1;
            int k = n-1;

            
            while(j<k) {
                int curr_sum = nums[i] + nums[j] + nums[k];
                if(curr_sum < 0){
                    j++;
                }
                else if(curr_sum > 0){
                    k--;
                }
                else{
                    ans.push_back({nums[i], nums[j], nums[k]});
                    j++;
                    while(nums[j] == nums[j-1] && j<k){
                        j++;
                    }
                }
            }
        }
        return ans;
    }
};