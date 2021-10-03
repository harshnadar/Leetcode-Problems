class Solution {
public:
    int dp[502][502];
    int n,m;
    vector<int> nums1, nums2;
    
    int solve(int i, int j){
        if(i>=n || j>=m) return 0;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        int ans= 0;
        for(int k=j;k<m;k++){
            if(nums2[k]==nums1[i]){
                ans = max(ans, 1+ solve(i+1,k+1));
            }
        }
        ans = max(ans,solve(i+1,j));
        
        return dp[i][j]=ans;
    }
    
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n=nums1.size();
        m=nums2.size();
        memset(dp,-1,sizeof dp);
        this->nums1 = nums1;
        this->nums2 = nums2;
        
        return solve(0,0);
    }
};