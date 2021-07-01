class Solution {
public:
    map<vector<int>, int> dp;
    
    int solve(vector<int>& price, vector<vector<int>>& special, vector<int>& needs){
        int n=needs.size(), s=special.size(), p1=0, p2=INT_MAX;
        if(dp.find(needs)!=dp.end()) return dp[needs];
        for(int i=0;i<n;i++){
            p1+=needs[i]*price[i];
        }
        int f;
        for(int i=0;i<s;i++){
            f=0;
            for(int j=0;j<n;j++){
                if(needs[j]-special[i][j]<0){
                    f=1;
                    break;
                }
            }
            if(!f){
                for(int j=0;j<n;j++){
                    needs[j]-=special[i][j];
                }
                p2=min(p2, special[i][n]+solve(price, special, needs));
                for(int j=0;j<n;j++){
                    needs[j]+=special[i][j];
                }
            }
        }
        return dp[needs]=min(p1,p2);
    }
    
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return solve(price, special, needs);
    }
};