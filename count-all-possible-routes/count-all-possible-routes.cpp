class Solution {
public:
    long long int dp[101][201];
    int finish;
    int n;
    int mod =1e9+7;
    
    vector<int> locations;
    
    int solve(int i, int fuel){
        // if(fuel<0) return 0;
        
        if(dp[i][fuel]!=-1) return dp[i][fuel];
        
        dp[i][fuel]=(i==finish);
        
        for(int j=0;j<n;j++){
            if(i!=j && fuel>=abs(locations[j]-locations[i])){
                dp[i][fuel] = (dp[i][fuel] + solve(j,fuel - abs(locations[j]-locations[i])))%mod;
            }
        }
        
        return dp[i][fuel];
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(dp,-1,sizeof dp);
        
        n=locations.size();
        this->locations = locations;
        this->finish = finish;
        
        return solve(start, fuel);
    }
};