class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> > dp;
        
        vector<int> v;
        v.push_back(1);
        dp.push_back(v);
        
        for(int i=1;i<numRows;i++){
            v.clear();
            v.resize(i+1);
            for(int j=0;j<=i;j++){
                if(j==0){
                    v[j]=dp[i-1][j];
                    continue;
                }
                else if(j==i){
                    v[j]=dp[i-1][j-1];
                    continue;
                }
                v[j] = dp[i-1][j-1]+dp[i-1][j];
            }
            dp.push_back(v);
        }
        
        return dp;
    }
};