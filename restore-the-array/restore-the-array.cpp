class Solution {
public:
    int dp[100002];
    int n;
    const int mod = 1e9+7;
    
    int solve(string& s, int k, int i){
        if(i>n) return 0;
        if(i==n) return 1;
        if(s[i]=='0') return 0;
        if(dp[i]!=-1) return dp[i];
        
        long long int ans=0;
        long long int num=0;
        for(int j=i;j<n;j++){
            num = (num*10) + (s[j]-'0');
            if(num>k) break;
            ans+=solve(s,k,j+1);
            ans%=mod;
        }
        return dp[i]=ans;
    }
    
    int numberOfArrays(string s, int k) {
        n=s.size();
        memset(dp,-1,sizeof dp);
        return solve(s,k,0);
    }
};