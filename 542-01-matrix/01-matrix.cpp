class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dx[] = {1,0,-1,0};
        int dy[] = {0,1,0,-1};
        int n = mat.size();
        int m = mat[0].size();

        queue<vector<int> > q;
        vector<vector<int> >dist(n, vector<int>(m,1e9));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0) {
                    q.push({i,j, 0});
                    dist[i][j] = 0;
                }
            }
        }

        while(!q.empty()){
            int curr_x = q.front()[1];
            int curr_y = q.front()[0];
            int curr_d = q.front()[2];
            q.pop();
            // if(dist[curr_x][curr_y] >= curr_d) continue;

            for(int i = 0;i<4;i++){
                int new_x = dx[i] + curr_x;
                int new_y = dy[i] + curr_y;

                if(new_x <0 || new_x >=m || new_y <0 || new_y>=n) continue;

                if(dist[new_y][new_x] > curr_d+1){
                    dist[new_y][new_x] = curr_d+1;
                    q.push({new_y, new_x, dist[new_y][new_x]});
                }
            }
        }
        return dist;

    }
};