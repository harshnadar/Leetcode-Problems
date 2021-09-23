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
        
        int res = (k+1)*(k+1) + solve(i+1,j,0);
        
        for(int m=i+1;m<=j;m++){
            if(boxes[m]==boxes[i]){
                res = max(res, solve(i+1,m-1,0) + solve(m,j,k+1));
            }
        }
        
        return dp[st_i][j][st_k] = res;
    }
    
    int removeBoxes(vector<int>& boxes) {
        n=boxes.size();
        
        memset(dp,-1,sizeof dp);
        
        this->boxes = boxes;
        
        return solve(0,n-1,0);
    }
};