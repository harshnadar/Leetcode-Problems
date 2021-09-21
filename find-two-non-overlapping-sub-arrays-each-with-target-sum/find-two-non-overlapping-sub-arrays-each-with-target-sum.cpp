class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        vector<vector<int> > dp(n+1,vector<int>(3,1e9));
        
        map<int, int> mp;
        
        for(int i=0;i<n+1;i++){
            dp[i][0]=0;
        }
        int cursum=0;
        mp[0]=0;
        
        for(int i=1;i<n+1;i++){
            int d=-1;
            
            cursum+=arr[i-1];
            mp[cursum]=i;
            
            if(mp.find(cursum-target)!=mp.end()) d=mp[cursum-target];
            
            for(int j=1;j<=2;j++){
                dp[i][j]=min(dp[i][j], dp[i-1][j]);
                if(d!=-1){
                    dp[i][j]=min(dp[i][j], dp[d][j-1]+i-d);
                }
            }
        }
        
        if(dp[n][2]>=1e9) return -1;
        return dp[n][2];
    }
};