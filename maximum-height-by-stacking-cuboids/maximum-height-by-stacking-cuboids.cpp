class Solution {
public:
    int maxHeight(vector<vector<int>>& A) {
        for(auto& a: A){
            sort(begin(a), end(a));
        }
        A.push_back({0,0,0});
        sort(begin(A), end(A));
        int n=A.size();
        vector<int> dp(n+1,0);
        
        dp[0]=0;
        int ans=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(A[j][0]<=A[i][0] && A[j][1]<=A[i][1] && A[j][2]<=A[i][2]){
                    dp[i]=max(dp[i], dp[j]+A[i][2]);
                    ans = max(ans, dp[i]);
                }
            }
        }
        // return *max_element(dp.begin(), dp.end());
        return ans;
    }
};