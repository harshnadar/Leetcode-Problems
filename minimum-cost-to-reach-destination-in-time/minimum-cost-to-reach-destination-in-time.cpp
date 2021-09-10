class Solution {
public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n= passingFees.size();
        int dp[n+1][maxTime+1];
        int t[n+1];
        for(int i=0;i<n;i++){
            t[i]=INT_MAX;
            for(int j=0;j<maxTime+1;j++){
                dp[i][j]=INT_MAX;
            }
        }
        
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
        
        pq.push({passingFees[0],0,0}); //cost,city,time
        
        vector<vector<pair<int, int> > > adj(n);
        
        for(auto it: edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        t[0]=0;
        dp[0][0]=passingFees[0];
        
        while(!pq.empty()){
            int cur = pq.top()[1];
            int cost = pq.top()[0];
            int time = pq.top()[2];
            pq.pop();
            
            if(cur == n-1) return cost;
            
            t[cur]=time;
            
            for(auto it: adj[cur]){
                if(time+it.second < t[it.first] && time+it.second <=maxTime){
                    if(cost+passingFees[it.first]<dp[it.first][time+it.second]){
                        dp[it.first][time+it.second] = cost+passingFees[it.first];
                        t[it.first]=it.second+time;
                        pq.push({dp[it.first][t[it.first]], it.first, t[it.first]});
                    }
                }
            }
        }
        return -1;
    }
};