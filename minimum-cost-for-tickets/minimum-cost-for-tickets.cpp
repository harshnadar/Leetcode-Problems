class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& cost) {
        int n=days.size();
        int dp[366];
        memset(dp,0,sizeof dp);
        int j=0;
        for(int i=1;i<366;i++){
            if(j<n && days[j]==i){
                int x=1e7;
                for(int k=i-1;k>=max(0,i-30);k--){
                    x=min(x,dp[k]+cost[2]);
                }
                int y=1e7;
                for(int k=i-1;k>=max(0,i-7);k--){
                    y=min(y,dp[k]+cost[1]);
                }
                dp[i]=min({dp[i-1]+cost[0],x,y});
                j++;
            }
            else dp[i]=dp[i-1];
        }
        // for(int i =0;i<50;i++) cout<<dp[i]<<" ";
        return dp[365];
    }
};