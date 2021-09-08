class Solution {
struct Compare{
        bool operator()(const pair<int, int>& f, const pair<int, int>& s) {
            return f.second < s.second; // equivalent to Java: (a, b) -> (b[1] - a[1])
        }
    };
public:
    int reachableNodes(vector<vector<int>>& edges, int M, int N) {
        int ans = 0;
        vector<vector<int>> g(N, vector<int>(N, -1));
        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        vector<bool> visited(N);
        for(vector<int> e : edges) g[e[0]][e[1]] = g[e[1]][e[0]] = e[2];
        pq.push({0, M});
        while(!pq.empty()) {
            pair<int, int> p = pq.top(); pq.pop();
            int start = p.first, move = p.second;
            if(visited[start]) continue;
            visited[start] = true;
            ans++;
            for(int i = 0; i < N; i++) {
                if(g[start][i] > -1) {
                    if(move > g[start][i] && !visited[i]) pq.push({i, move-g[start][i]-1});
                    g[i][start] -= min(move, g[start][i]);
                    ans += min(move, g[start][i]);
                }
            }
        }
        return ans;
    }
};