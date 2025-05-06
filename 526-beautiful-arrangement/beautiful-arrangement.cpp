class Solution {
public:
    int ans;
    void solve(vector<bool> nums, int j){
        if(j == nums.size()-1) ans++;
        for(int i=1;i<nums.size();i++){
            if(nums[i] == false && ((j+1)%i==0 || i%(j+1)==0)){
                nums[i] = true;
                solve(nums, j+1);
                nums[i] = false;
            }
        }
        return;
    }
    int countArrangement(int n) {
        vector<bool> nums(n+1, false);
        solve(nums, 0);
        return ans;
    }
};