class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rev_graph(n);
        vector<int> out(n,0);
        for(int i = 0;i<n;i++){
            for(auto it: graph[i]){
                out[i]++;
                rev_graph[it].push_back(i);
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(out[i] == 0) {
                ans.push_back(i);
                q.push(i);
            }
        }
        

        while(!q.empty()){
            int curr_node = q.front();
            q.pop();

            for(int child: rev_graph[curr_node]){
                out[child]--;
                if(out[child]==0){
                    q.push(child);
                    ans.push_back(child);
                }
            }
        }

        sort(ans.begin(), ans.end());

        return ans; 
    }
};