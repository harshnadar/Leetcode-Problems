#define pb push_back
class Solution {
public:
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
        vector<pair<int, int>> adj[n];
        for(vector<int> it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        priority_queue<array<int, 3>, vector<array<int, 3>>, greater<array<int, 3>>> pq;
        
        vector<int> dist(n, INT_MAX);
        pq.push({0, src, 0});
        
        
        while(!pq.empty()) {
            auto [price, vertex, edge_steps] = pq.top();
            if(vertex == dst) return price;
            pq.pop();
            if(edge_steps > k) continue;
            
            if(dist[vertex] != INT_MAX) {
                if(dist[vertex] < edge_steps) continue;
            }
            
            dist[vertex] = edge_steps;
            
            for(pair<int, int> v : adj[vertex]) {
                pq.push({price + v.second, v.first, edge_steps+1});
            }
        }
        return -1;
    }
};