class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        int n=pre.size();
        vector<int> adj[num+1];
        int in[num+1];
        memset(in,0,sizeof in);
        for(auto it: pre){
            adj[it[0]].push_back(it[1]);
            in[it[1]]++;
        }
        queue<int> q;
        vector<int> res;
        for(int i=0;i<num;i++){
            if(in[i]==0) q.push(i);
        }
        while(!q.empty()){
            int cur=q.front();
            q.pop();
            res.push_back(cur);
            for(auto node: adj[cur]){
                in[node]--;
                if(in[node]==0) q.push(node);
            }
        }
        return (res.size()==num);
    }
};