#define f(a,b,i) for(int i=a;i<b;i++)
class Solution {
public:
    int n,m;
    int dp[13][1<<12];
    vector<int> mnsz;
    
    int dfs(vector<vector<int> >& cost, int i, int mask){
        if(dp[i][mask]!=-1) return dp[i][mask];
        int res = ((i>=n)?0:INT_MAX);
        if(i>=n){
            f(0,m,j){
                res+=mnsz[j]*((mask&(1<<j)) ==0);
            }
        }
        else{
            f(0,m,j){
                res=min(res,cost[i][j]+dfs(cost,i+1,mask|(1<<j)));
            }
        }
        
        return dp[i][mask]=res;
    }
    
    int connectTwoGroups(vector<vector<int>>& cost) {
        n=cost.size(), m=cost[0].size();
        mnsz.resize(m,INT_MAX);
        memset(dp,-1,sizeof dp);
        f(0,m,j){
            f(0,n,i){
                mnsz[j]=min(mnsz[j],cost[i][j]);
            }
        }
        return dfs(cost,0,0);
    }
};