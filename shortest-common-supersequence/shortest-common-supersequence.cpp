class Solution {
public:
    vector<vector<int> > dp;
    int n,m;
    
    string scs(string x, string y){
        int index=dp[n][m];
        int i=n,j=m;
        string res;
        while(i>0 && j>0){
            if(x[i-1]==y[j-1]){
                res.push_back(x[i-1]);
                i--,j--;
            }
            else if(dp[i-1][j]<dp[i][j-1]){
                res.push_back(x[i-1]);
                i--;
            }
            else if(dp[i][j-1]<=dp[i-1][j]){
                res.push_back(y[j-1]);
                j--;
            }
        }
        while(i>0){
            res.push_back(x[i-1]);
            i--;
        }
        while(j>0){
            res.push_back(y[j-1]);
            j--;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    
    void solve(string x, string y){
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                if(!i) dp[i][j]=j;
                else if(!j) dp[i][j]=i;
                else if(x[i-1]==y[j-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=1+min(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    string shortestCommonSupersequence(string str1, string str2) {
        n=str1.size();
        m=str2.size();
        dp.resize(n+1, vector<int>(m+1,0));
        solve(str1, str2);
        for(int i=0;i<n+1;i++){
            for(int j=0;j<m+1;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        // return "";
        return scs(str1, str2);
    }
};