class Solution {
public:
    void setZeroes(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        map<int, int> row, col;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    row[i]++;
                    col[j]++;
                }
            }
        }
        
        for(auto it: row){
            for(int j=0;j<m;j++){
                mat[it.first][j]=0;
            }
        }
        
        for(auto it: col){
            for(int i=0;i<n;i++){
                mat[i][it.first]=0;
            }
        }
        
        // return  mat;
    }
};