class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        int prod=1;
        for(int i=0;i<n;i++){
            prod*=nums[i];
            if(nums[i]==0) count++;
        }
        int c=1;
        if(count==1){
            for(int i=0;i<n;i++){
                if(nums[i]==0) continue;
                c*=nums[i];
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(nums[i]!=0){
                ans.push_back(prod/nums[i]);
            }
            else{
                if(count==1){
                    ans.push_back(c);
                }
                else ans.push_back(0);
            }
        }
        return ans;
    }
};