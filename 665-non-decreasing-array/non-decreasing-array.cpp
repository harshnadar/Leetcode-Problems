class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int first_inflection = -1;
        for(int i = 0;i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]){
                if(first_inflection == -1){
                    first_inflection = i;
                }
                else return false;
            }
        }

        if(first_inflection == -1 || first_inflection == 0 || first_inflection == nums.size() - 2){
            return true;
        }
        if(nums[first_inflection -1] <= nums[first_inflection+1] || nums[first_inflection + 2] >= nums[first_inflection]) return true;

        return false;

    }
};