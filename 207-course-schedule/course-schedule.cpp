class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& pre) {
        
        int n = pre.size();
        map<int, vector<int> > mp;
        int in[num+1];
        memset(in,0,sizeof in);
        for(auto it: pre){
            mp[it[1]].push_back(it[0]);
            in[it[0]]++;
        }

        queue<int> q;
        for(int i=0;i<num;i++){
            if(in[i]==0) q.push(i);
        }
        vector<int> res;
        while(!q.empty()){
            int curr_node = q.front();
            q.pop();
            res.push_back(curr_node);
            for(auto child: mp[curr_node]){
                in[child]--;
                if(in[child] == 0) q.push(child);
            }
        }

        return res.size() == num;

    }
};