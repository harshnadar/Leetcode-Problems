class Solution {
public:
    
    int n; int dp[101][101][101];
    vector<int> houses;
    
    int solve(int left, int right, int k){
        if(left==right) return 0;
        if(dp[left][right][k]!=-1) return dp[left][right][k];
        
        int res = 1e8;
        
        if(k==1){
            int mid = (left+right)/2;
            int sum=0;
            for(int i=left; i<=right;i++){
                sum+=abs(houses[i]-houses[mid]);
            }
            
            return sum;
        }
        
        else{
            for(int t=left;t<right;t++){
                res = min(res, solve(left,t, k-1) + solve(t+1,right,1));
            }
        }
        
        return dp[left][right][k]=res;
        
    }
    int minDistance(vector<int>& houses, int k) {
        n=houses.size();
        memset(dp,-1,sizeof dp);
        sort(houses.begin(), houses.end());
        
        this->houses = houses;
        
        return solve(0,n-1,k);
    }
};