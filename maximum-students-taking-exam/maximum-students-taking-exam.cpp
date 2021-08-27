class Solution {
public:
    int maxStudents(vector<vector<char>>& seats) {
        int n=seats.size();
        int m=seats[0].size();
        vector<int> masks;
        for(int i=0;i<n;i++){
            int cur=0;
            for(int j=0;j<m;j++){
                cur = cur*2 + (seats[i][j]=='.');
            }
            masks.push_back(cur);
        }
        
        vector<vector<int> > dp(n+1, vector<int>(1<<m, -1));
        
        dp[0][0]=0;
        
        for(int i=1;i<=n;i++){
            int mask = masks[i-1];
            
            for(int j=0;j<(1<<m);j++){
                if ((j & mask) == j && !(j & (j >> 1))) {
					// f[i][j] may transit from f[i -1][k]
                    for (int k = 0; k < (1 << m); ++k) {
						// !(j & (k >> 1)): no students in the upper left positions
						// !((j >> 1) & k): no students in the upper right positions
						// f[i - 1][k] != -1: the previous state is valid
                        if (!(j & (k >> 1)) && !((j >> 1) & k) && dp[i - 1][k] != -1) {
                            dp[i][j] = max(dp[i][j], dp[i - 1][k] + __builtin_popcount(j));
                        }
                    }
                }
            }
        }
        return *max_element(dp[n].begin(), dp[n].end());
    }
};