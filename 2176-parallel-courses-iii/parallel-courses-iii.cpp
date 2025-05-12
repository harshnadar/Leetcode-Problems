class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int> > adj(n);
        vector<int> in(n,0);
        for(auto it: relations){
            adj[it[0] - 1].push_back(it[1] - 1);
            in[it[1]-1]++;
        }
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
        int ans_time = 0;
        for(int i=0;i<n;i++){
            if(in[i] == 0) pq.push({time[i], i});
        }
        while(!pq.empty()){
            int curr_course = pq.top()[1];
            int curr_time = pq.top()[0];

            pq.pop();
            ans_time = max(ans_time, curr_time);

            for(auto it: adj[curr_course]){
                in[it]--;
                if(in[it] == 0){
                    pq.push({curr_time + time[it], it});
                }
            }

        }
        return ans_time;
    }
};