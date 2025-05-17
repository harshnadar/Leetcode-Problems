class Solution {
public:

    bool isPossible(vector<int>& nums) {
        map<int, int> count, tails;
        for(int i=0;i<nums.size();i++){
            count[nums[i]]++;
        }
        for(auto &i: nums){
            if(!count[i]) continue;
            count[i]--;
            if(tails[i-1]>0){
                tails[i-1]--;
                tails[i]++;
            }
            else if(count[i+1] > 0 && count[i+2] > 0){
                count[i+1]--;
                count[i+2]--;
                tails[i+2]++;
            }
            else return false;
        }
        return true;
    }
};