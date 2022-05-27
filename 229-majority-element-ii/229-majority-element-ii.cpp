class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        long long int num1 = -1e10, num2 = -1e10;
        int c1 = 0, c2=0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==num1) c1++;
            else if(nums[i]==num2) c2++;
            else if(c1==0){
                c1++;
                num1=nums[i];
            }
            else if(c2==0){
                c2++;
                num2 = nums[i];
            }
            else{
                c1--;
                c2--;
            }
        }
        
        vector<int> v;
        int count1=0, count2=0;
        for(int i=0;i<n;i++){
            if(num1 == nums[i]) count1++;
            else if(num2 == nums[i]) count2++;
        }
        
        if(count1>n/3) v.push_back(num1);
        if(count2>n/3) v.push_back(num2);
        return v;
    }
};