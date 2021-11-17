class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int ind;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ind = abs(nums[i]);
            nums[ind]*=-1;
            // cout<<nums[ind]<<endl;
            
            if(nums[ind]>0){
                return ind;
            }
        }
        return -1;
    }
};