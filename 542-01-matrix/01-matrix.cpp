class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> ans(n, vector<int>(m,0));

        queue<vector<int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) q.push({i,j,0});
            }
        }

        int timer = 0;
        while(!q.empty()){
            vector<int> curr_node = q.front();
            q.pop();

            for(int i=0;i<4;i++){
                int x = curr_node[0] + dx[i];
                int y = curr_node[1] + dy[i];

                if(x<0 || y<0 || x>=n || y>=m) continue;
                if(mat[x][y] == 0) continue;

                ans[x][y] = curr_node[2] + 1;
                mat[x][y] = 0;
                q.push({x,y,ans[x][y]});
            }
        }

        return ans;

    }
};