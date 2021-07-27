class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        if(n<=1) return n;
        vector<int> len(n,1), count(n,1);
        for(int j=1;j<n;j++){
            for(int i=0;i<j;i++){
                if(nums[j]>nums[i]){
                    if(len[j]<=len[i]){
                        len[j]=len[i]+1;
                        count[j]=count[i];
                    }
                    else if(len[j]==len[i]+1){
                        count[j]+=count[i];
                    }
                }
            }
        }
        int res=0;
        int longest=*max_element(len.begin(), len.end());
        for(int i=0;i<n;i++){
            if(len[i]==longest){
                res+=count[i];
            }
        }
        return res;
    }
};