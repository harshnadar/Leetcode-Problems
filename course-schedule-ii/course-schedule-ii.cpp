class Solution {
public:
    vector<int> findOrder(int num, vector<vector<int>>& pre) {
        int n=pre.size();
        int in[num+1];
        vector<int> adj[num+1];
        memset(in,0,sizeof in);
        for(auto it: pre){
            adj[it[1]].push_back(it[0]);
            in[it[0]]++;
        }
        priority_queue<int, vector<int>, greater<int> > q;
        vector<int> res;
        for(int i=0;i<num;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int cur=q.top();
            res.push_back(cur);
            q.pop();
            for(auto node: adj[cur]){
                in[node]--;
                if(in[node]==0) q.push(node);
            }
        }
        return ((res.size()==num)?res:vector<int>());
    }
};