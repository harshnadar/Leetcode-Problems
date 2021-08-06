class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red_edges, vector<vector<int>>& blue_edges) {
        vector<vector<pair<int, int> > > graph(n);
        for(auto it: red_edges){
            graph[it[0]].push_back({it[1], 0});
        }
        for(auto it: blue_edges){
            graph[it[0]].push_back({it[1],1});
        }
        queue<vector<int> > q;
        q.push({0,0,-1}); //node, dist, color
        vector<int> dist(n,-1);
        while(!q.empty()){
            vector<int> cur=q.front();
            q.pop();
            dist[cur[0]]= (dist[cur[0]]!=-1)?dist[cur[0]]:cur[1];
            for(auto &adj: graph[cur[0]]){
                if(adj.second != cur[2] && adj.first!=-1){
                    q.push({adj.first, cur[1]+1, adj.second});
                    adj.first=-1;
                }
            }
        }
        return dist;
    }
};