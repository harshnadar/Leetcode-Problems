class Solution {
public:
    map<int, vector<int>> mp;
    vector<bool> vis, dfs_vis;
    bool cycleDetection(int node, vector<bool>& vis, vector<bool>& dfs_vis){
        vis[node] = true;
        dfs_vis[node] = true;

        for(auto child: mp[node]){
            if(!vis[child]){
                if(cycleDetection(child, vis, dfs_vis)) return true;
            }
            else if(dfs_vis[child]) return true;
        }
        dfs_vis[node] = false;
        return false;
    }
    bool canFinish(int num, vector<vector<int>>& pre) {
        vis.resize(num, 0);
        dfs_vis.resize(num,0);
        
        // int in[num+1];
        // memset(in,0,sizeof in);
        for(auto it: pre){
            mp[it[1]].push_back(it[0]);
        }

        for(int i=0;i<num;i++){
            if(!vis[i]){
                if(cycleDetection(i, vis, dfs_vis)) return false;
            }
        }

        return true;
    }
};