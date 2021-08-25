class Solution {
public:
    int dp[1002][1002][4];
    string s;
    int n;
    const int mod = 1e9+7;
    
    int solve(int start, int end, int alpha){
        if(start>end) return 0;
        if(start==end){
            return s[start]==alpha+'a';
        }
        if(dp[start][end][alpha]!=-1) return dp[start][end][alpha];
        
        int dev = 0;
        
        if(s[start]==s[end] && s[start]==(alpha+'a')){
			dev=2;
			for(int i=0;i<4;i++)
				dev=(dev + solve(start+1,end-1,i) )%mod;
		}else{
			dev= (dev + solve(start,end-1,alpha))%mod;
			dev= (dev + solve(start+1,end,alpha))%mod;
			dev= (dev - solve(start+1,end-1,alpha))%mod;
			if(dev<0)dev+=mod;
		}
		
		dp[start][end][alpha]=dev;
		return dev;
    }
    
    int countPalindromicSubsequences(string s) {
        this->s=s;
        memset(dp,-1,sizeof dp);
        n=s.size();
        int ans = 0;
        for(int i=0;i<4;i++){
            ans = (ans+solve(0,n-1,i))%mod;
        }
        return ans;
    }
};