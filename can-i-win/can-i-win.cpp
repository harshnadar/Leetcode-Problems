class Solution {
public:
    int dp[1<<20];
    int m;
    
    int solve(int sum, int mask){
        if(dp[mask]!=0) return dp[mask]>0;
        if(sum<=0) return false;
        
        for(int i=0;i<m;i++){
            if(!(mask&(1<<i)) && !solve(sum-(i+1), mask^(1<<i))){
                dp[mask]=1;
                return true;
            }
        }
        dp[mask]=-1;
        return false;
    }
    
    bool canIWin(int M, int target) {
        m=M;
        int sum = (m*(m+1))/2;
        if(target<2) return true;
        if(sum<target) return false;
        if(sum == target) return m%2;
        
        return solve(target,0);
    }
};