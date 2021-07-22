class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int mid=0, lo=0,hi=n-1;
        while(mid<=hi){
            if(nums[mid]==0){
                swap(nums[mid],nums[lo]);
                mid++;
                lo++;
            }
            else if(nums[mid]==2){
                swap(nums[mid],nums[hi]);
                // mid++;
                hi--;
            }
            else mid++;
        }
        
    }
};