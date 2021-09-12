class Solution {

public:
vector<vector<int> > res;
vector<vector<int>> visited;

void dfs(int i,int j,vector<vector<int>>& matrix,int pre,int label){
    if(i<0||i>matrix.size()-1||j<0||j>matrix[0].size()-1||matrix[i][j]<pre||visited[i][j]==3||visited[i][j]==label)
        return;
    visited[i][j]+=label;
    if(visited[i][j]==3) res.push_back({i,j});
    dfs(i+1,j,matrix,matrix[i][j],label);
    dfs(i-1,j,matrix,matrix[i][j],label);
    dfs(i,j+1,matrix,matrix[i][j],label);
    dfs(i,j-1,matrix,matrix[i][j],label);
}

vector<vector<int>> pacificAtlantic(vector<vector<int>>& matrix) {
    if(matrix.empty()) return res;
    int m=matrix.size();
    int n=matrix[0].size();
    visited.resize(m,vector<int>(n,0));
    for(int j=0;j<n;j++){
        dfs(0,j,matrix,INT_MIN,1);
        dfs(m-1,j,matrix,INT_MIN,2);
    }
    
    for(int i=0;i<m;i++){
        dfs(i,0,matrix,INT_MIN,1);
        dfs(i,n-1,matrix,INT_MIN,2);
    }
    return res;
}
};