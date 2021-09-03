class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=ages.size();
        vector<vector<int> > v;
        for(int i=0;i<n;i++){
            v.push_back({ages[i], scores[i]});
        }
        sort(v.begin(), v.end());
        int dp[n+1];
        memset(dp,0,sizeof dp);
        for(int i=0;i<n;i++){
            cout<<v[i][0]<<"\n";
            dp[i]=v[i][1];
            for(int j=0;j<i;j++){
                if(v[i][1]>=v[j][1] && dp[j]+v[i][1]>=dp[i]){
                    dp[i]=dp[j]+v[i][1];
                }
                // else if(v[i][1]>v[j][1] && dp[j]+v[i][1]>=dp[i]){
                //     dp[i]=dp[j]+v[i][1];
                // }
            }
        }
        return *max_element(dp,dp+n);
    }
};