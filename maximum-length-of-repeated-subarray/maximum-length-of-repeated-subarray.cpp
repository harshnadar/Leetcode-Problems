class Solution {
public:
    int dp[1002][1002];
    int n,m;
    
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,0,sizeof dp);
        n=nums1.size();
        m=nums2.size();
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1] == nums2[j-1]){
                    dp[i][j]=dp[i-1][j-1]+1;
                }
                else dp[i][j]=0;
            }
        }
        int mx= INT_MIN;
        for(int i=1;i<n+1;i++){
            for(int j=1;j<m+1;j++){
                mx=max(dp[i][j], mx);
            }
            // cout<<"\n";
        }
        return mx;
    }
};