class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0, ans=0;
        int p[n]; memset(p,0,sizeof p);
        while(j<n){
            if(nums[j]==1){
                j++;
                ans=max(ans,j-i);
            }
            else if(k){
                p[j]=1;
                j++;
                k--;
                ans=max(ans, j-i);
            }
            else{
                k+=p[i];
                i++;
                j=max(j,i);
            }
        }
        return ans;
    }
};