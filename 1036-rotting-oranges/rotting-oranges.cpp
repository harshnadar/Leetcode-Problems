class Solution {
public:
    int dx[4] = {1,0,-1,0};
    int dy[4] = {0,1,0,-1};
    int orangesRotting(vector<vector<int>>& grid) {
        queue<vector<int>> q;
        int n = grid.size();
        int m = grid[0].size();
        int good = 0;
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                if(grid[i][j] == 2){
                    q.push({i,j,0});
                }
                if(grid[i][j] == 1) good++;
            }
        }
        if(good == 0) return 0;
        int ans = 1e7;


        while(!q.empty()){
            vector<int> curr_node = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int x = curr_node[0] + dx[i];
                int y = curr_node[1] + dy[i];
                int time = curr_node[2];

                if(x<0 || y<0 || x>=n || y>=m) continue;
                if(grid[x][y] == 2 || grid[x][y] == 0) continue;

                good--;
                q.push({x,y,time+1});
                grid[x][y] = 2;
                ans = time+1;
            }
        }
        if(good!=0) return -1;
        return ans;
    }
};