class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        vector<int> copy = nums;
        sort(copy.begin(), copy.end(), greater<int>());
        if(copy == nums){
            sort(nums.begin(), nums.end());
            return;
            // return nums;
        }
        
        next_permutation(nums.begin(), nums.end());
        // return nums;
    }
};