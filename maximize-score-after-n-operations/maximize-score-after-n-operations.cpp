class Solution {
public:
    int n;
    int dp[1<<14][8];
    int solve(int i, int mask, vector<int>& nums){
        if(i>(n/2) || mask == (1<<n)-1) return 0;
        if(dp[mask][i]!=-1) return dp[mask][i];
        
        int sum=0;
        for(int j=0;j<(n);j++){
            for(int k=j+1;k<(n);k++){
                int newMask = (1<<j) + (1<<k);
                if((mask&newMask)==0 && j!=k){
                    // int newMask = mask|(1<<j)|(1<<k);
                    sum= max(sum, i*(__gcd(nums[j], nums[k])) + solve(i+1, mask+newMask, nums));
                    // if(sum==15) cout<<i<<" "<<j<<" "<<k<<endl;
                }
            }
        }
        // cout<<i<<" "<<sum<<endl;
        return dp[mask][i]=sum;
    }
    int maxScore(vector<int>& nums) {
        n=nums.size();
        memset(dp,-1,sizeof dp);
        return solve(1,0,nums);
    }
};