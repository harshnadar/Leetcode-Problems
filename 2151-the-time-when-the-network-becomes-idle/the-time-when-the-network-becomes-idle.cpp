class Solution {
public:
    int networkBecomesIdle(vector<vector<int>>& edges, vector<int>& patience) {
        int n = patience.size();
        vector<vector<int> > adj(n);
        for(auto it: edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dist(n,1e9);
        dist[0] = 0;
        queue<int> q;
        q.push(0);
        int curr_dist = 0;

        while(!q.empty()){
            int curr_node = q.front();
            q.pop();

            for(auto it: adj[curr_node]){
                int new_node = it;

                if(dist[new_node]!=1e9) continue;

                dist[new_node] = dist[curr_node]+1;
                q.push(new_node);
            }
        }

        
        vector<int> num(n,0);
        for(int i=1;i<n;i++){
            num[i] = (2*dist[i]-1)/patience[i];
            cout<<i<<" "<<num[i]<<" "<<dist[i]<<" "<<patience[i]<<endl;
        }
        int ans = -1;
        for(int i=1;i<n;i++){
            ans = max(ans, num[i]*patience[i] + 2*dist[i]);
        }
        return ans+1;
    }
};