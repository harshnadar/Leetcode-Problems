class Solution {
public:
    int minDifficulty(vector<int>& job, int d) {
        int n=job.size();
        if(d>n) return -1;
        if(d==n) return accumulate(job.begin(), job.end(), 0);
        vector<vector<int> > dp(n+1, vector<int> (n+1, 1e6));
        int m=job[0];
        for(int i=1;i<n+1;i++){
            m=max(job[i-1], m);
            dp[1][i]= m;
        }
        for(int k=2;k<n+1;k++){
            for(int i=1;i<n+1;i++){
                if(i==k) dp[k][i]=accumulate(job.begin(), job.begin()+i, 0);
                else if(i<k) dp[k][i]=-1;
                else{
                    int mx=job[i-1];
                    for(int j=i;j>0 && j>=k ;j--){
                        mx=max(mx, job[j-1]);
                        dp[k][i]=min({dp[k][i], dp[k-1][j-1]+mx, dp[k][j]+mx});
                    }
                }
            }
        }
        for(int i=1;i<n+1;i++){
            for(int j=1;j<n+1;j++){
                cout<<dp[i][j]<<' ';
            }
            cout<<"\n";
        }
        return dp[d][n];
    }
};