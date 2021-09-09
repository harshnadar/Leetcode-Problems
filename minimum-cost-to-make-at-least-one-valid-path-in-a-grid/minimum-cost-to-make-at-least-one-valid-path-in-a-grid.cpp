class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int n=grid.size();
        cout<<n<<endl;
        // return n;
        int m=grid[0].size();
        vector<vector<pair<int, int> > > adj(n*m);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(j!=m-1){
                    adj[m*i+j].push_back({m*i+j+1, ((grid[i][j]==1)?0:1)});
                }
                if(i!=0){
                    adj[m*i+j].push_back({m*(i-1)+j,((grid[i][j]==4)?0:1)});
                }
                if(i!=n-1){
                    adj[m*i+j].push_back({m*(i+1)+j,((grid[i][j]==3)?0:1)});
                }
                if(j!=0){
                    adj[m*i+j].push_back({m*i+j-1,((grid[i][j]==2)?0:1)});
                }
            }
        }
        
        priority_queue<pair<int,int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
        
        // int dist[n];
        vector<int> dist(n*m, 1e8);
        
        pq.push({0,0});
        dist[0]=0;
        
        while(!pq.empty()){
            int cur = pq.top().second;
            int cur_d = pq.top().first;
            
            pq.pop();
            
            if(cur_d > dist[cur]) continue;
            
            for(auto it: adj[cur]){
                int x= it.second + cur_d;
                int y=it.first;
                
                if(dist[y]>x){
                    dist[y]=x;
                    pq.push({dist[y],y});
                }
            }
        }
        return dist[n*m-1];
        
    }
};