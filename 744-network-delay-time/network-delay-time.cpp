class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>> > adj(n+1);
        for(auto it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int>>> pq;
        pq.push({0, k});

        vector<int> dist(n+1, 1e9);
        dist[k] = 0;
        int ans = -1;

        while(!pq.empty()){
            int curr_node = pq.top()[1];
            int curr_dist = pq.top()[0];
            pq.pop();

            if(dist[curr_node]<curr_dist) continue;

            for(auto it: adj[curr_node]){
                int new_node = it.first;
                int d = it.second;
                int new_dist = d+curr_dist;

                if(new_dist < dist[new_node]){
                    dist[new_node] = new_dist;
                    pq.push({new_dist, new_node});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(dist[i]==1e9) return -1;
            ans = max(dist[i], ans);
        }
        return ans;
    }
};