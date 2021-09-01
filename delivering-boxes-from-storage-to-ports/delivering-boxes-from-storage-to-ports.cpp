class Solution {
public:
    int boxDelivering(vector<vector<int>>& boxes, int mp, int mb, int mw) {
        int n=boxes.size();
        vector<int> dp(n+1);
        int i=0, cost=1, wt=0;
        
        for(int j=0;j<n;j++){
            if(j==0 || boxes[j][0]!=boxes[j-1][0]) cost++;
            wt+=boxes[j][1];
            
            while((j-i+1)>mb || wt>mw || (i<j && dp[i]==dp[i+1])){
                wt-=boxes[i][1];
                
                if(boxes[i][0]!=boxes[i+1][0]) cost--;
                
                i++;
            }
            dp[j+1]=dp[i]+cost;
        }
        return dp[n];
    }
};