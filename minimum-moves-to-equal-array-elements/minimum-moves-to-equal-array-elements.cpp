class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        
        long long int x = *min_element(nums.begin(), nums.end());
        long long int sum = accumulate(nums.begin(), nums.end(),0);
        return sum - n*x;
        
    }
};