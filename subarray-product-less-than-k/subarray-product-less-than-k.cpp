class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int count=0;
        int i=0;int j=0;
        int prod=1;
        while(j<n){
            prod*=nums[j];
            if(prod<k) {j++;continue;}
            else{
                while(prod>=k && i<=j){
                    count+=(j-i);
                    prod/=nums[i];
                    i++;
                    cout<<j<<" "<<i<<"\n";
                }
            }
            j++;
        }
        cout<<j<<" "<<i<<"\n";
        count+=((j-i)*(j-i+1))/2;
        return count;
    }
};