class Solution {
public:
    int n;
    int dp[502][502][2];
    
    int solve(int l, int r, vector<int>& piles, int id){
        if(r<l) return 0;
        if(dp[l][r][id]!=-1) return dp[l][r][id];
        int c  = id^1;
        if(id==0){
            return dp[l][r][id]= min(-piles[l]+solve(l+1,r, piles,c), -piles[r]+solve(l,r-1,piles,c));
        }
        else{
            return dp[l][r][id] = max(piles[l]+solve(l+1,r,piles,c), piles[r]+solve(l,r-1,piles,c));
        }
        return dp[l][r][id];
    }
    
    bool stoneGame(vector<int>& piles) {
        n=piles.size();
        memset(dp,-1,sizeof dp);
        return solve(0,n-1,piles, 1)>=0;
    }
};