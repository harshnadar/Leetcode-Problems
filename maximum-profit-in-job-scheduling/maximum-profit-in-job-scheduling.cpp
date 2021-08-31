class Solution {
public:
    vector<vector<int> > job;
    map<int,int> dp;
    int n;
    
    int solve(int pos){
        if(pos>=n) return 0;
        // if(pos==n) return 0;
        
        if(dp.find(pos)!=dp.end()) return dp[pos];
        
        int i;
        for(i=pos+1;i<n;i++){
            if(job[i][0]>=job[pos][1]) break;
        }
        // cout<<job[pos][2]<<endl;
        return dp[pos]= max(solve(pos+1), solve(i)+job[pos][2]);
    }
    
    int jobScheduling(vector<int>& start, vector<int>& end, vector<int>& profit) {
        // memset(dp,-1,sizeof dp);
        n=profit.size();
        for(int i=0;i<n;i++){
            job.push_back({start[i], end[i], profit[i]});
        }
        sort(job.begin(), job.end());
        
        return solve(0);
    }
};