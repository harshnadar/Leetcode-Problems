class Solution {
public:
    vector<vector<int> > job;
    map<int,long long int> dp;
    int m;
    
    long long int solve(int pos){
        if(pos>=m) return 0;
        // if(pos==n) return 0;
        
        if(dp.find(pos)!=dp.end()) return dp[pos];
        
        int i;
        
        int hi=m-1;
        int lo=pos+1;
        int next=hi+1;
        
        while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            if(job[mid][0]>=job[pos][1]){
                next=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        }
        
        // for(i=pos+1;i<m;i++){
        //     if(job[i][0]>=job[pos][1]) break;
        // }
        // cout<<job[pos][2]<<endl;
        return dp[pos]= max(solve(pos+1), solve(next)+job[pos][2]);
    }

    long long maxTaxiEarnings(int n, vector<vector<int>>& rides) {
        for(auto& it: rides){
            it[2]+=(it[1]-it[0]);
        }
        m=rides.size();
        sort(rides.begin(), rides.end());
        this->job = rides;
        // for(auto it: job) cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        return solve(0);
    }
};