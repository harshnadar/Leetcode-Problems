class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int count_1=0;
        int n=nums.size();
        
        if(n==1)return 0;
        
        for(int i=0;i<n;i++){
            if(nums[i]==1)
                count_1++;
        }
        
        int windowsize=count_1;   // window size for counting maximum  no. of 1s
        count_1=0;
        
         for(int i=0;i<windowsize;i++){
             if(nums[i]==1)count_1++;
        }
        
        int mx=count_1;           //for storing maximum count of 1s in a window
        for(int i=windowsize;i<n+windowsize;i++){
            if(nums[i%n]==1)
                count_1++;
            if(nums[(i-windowsize)%n]==1)
                count_1--;
            mx=max(count_1,mx);
        }
        
        return windowsize-mx;
    }
};