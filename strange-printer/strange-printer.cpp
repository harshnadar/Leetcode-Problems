class Solution {
public:
    int dp[101][101][101];
    int n;
    vector<int> boxes;
    
    int solve(int i, int j, int k){
        if(i>j) return 0;
        
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        
        int st_i = i, st_k = k;
        
        while(j>=i+1 && boxes[i+1]==boxes[i]){
            i++;
            k++;
        }
        
        int res = 1 + solve(i+1,j,0);
        
        for(int m=i+1;m<=j;m++){
            if(boxes[m]==boxes[i]){
                res = min(res, solve(i+1,m-1,0) + solve(m,j,k+1));
            }
        }
        
        return dp[st_i][j][st_k] = res;
    }
    
    int strangePrinter(string s) {
        for(auto it: s){
            boxes.push_back(it-'a'+1);
        }
        n=s.size();
        for(auto it: boxes) cout<<it<<" ";
        memset(dp,-1,sizeof dp);
        
        return solve(0,n-1,0);
    }
};