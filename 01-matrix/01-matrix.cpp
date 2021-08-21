class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int dx[4]={1,0,0,-1};
        int dy[4]={0,1,-1,0};
        int n = mat.size(), m=mat[0].size();
        queue<pair<int, int> >q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0) q.push({i,j});
                else mat[i][j]=-1;
            }
        }
        
        while(!q.empty()){
            int r= q.front().first;
            int c= q.front().second;
            q.pop();
            for(int j=0;j<4;j++){
                int nr = r+dx[j];
                int nc = c+dy[j];
                if(nr<0 || nr>=n || nc<0 || nc>=m || mat[nr][nc]!=-1) continue;
                mat[nr][nc]=mat[r][c]+1;
                q.push({nr,nc});
            }
            // q.pop();
        }
        return mat;
    }
};