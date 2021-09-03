class Solution {
public:
    vector<int> func(int n){
        vector<int> ans;
        for(int i=1;i<n/2;i++){
            if(n%i ==0) ans.push_back(i);
        }
        return ans;
    }
    
    int minSteps(int n) {
        if(n==1) return 0;
        int dp[n+1];
        dp[1]=0;
        dp[2]=2;
        for(int i=3;i<=n;i++){
            dp[i]=i;
            vector<int> v = func(i);
            for(auto it: v){
                dp[i] = min(dp[i], dp[it]+(i/it));
            }
        }
        return dp[n];
    }
};