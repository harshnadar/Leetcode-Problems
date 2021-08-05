class Solution {
public:
    void dfs(vector<vector<int>>&stones,int index,bool*visited){
        visited[index]=true;
        // int result=0;
        for(int i=0;i<stones.size();i++)
            if(!visited[i]&&(stones[i][0]==stones[index][0]||stones[i][1]==stones[index][1]))
                dfs(stones,i,visited);
        return;
    }
    int removeStones(vector<vector<int>>&stones) {
        bool visited[stones.size()];
        memset(visited,0,stones.size());
        int result=0;
        int cc=0;
        for(int i=0;i<stones.size();i++){
            if(visited[i]){continue;}
            dfs(stones,i,visited);
            cc++;
        }
        return stones.size()-cc;
    }
};