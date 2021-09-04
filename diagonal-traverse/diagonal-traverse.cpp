class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int n=mat.size();
        int m = mat[0].size();
        
        vector<int> ans;
        for(int i=0;i<n+m-1;i++){
            vector<int> v;
            for(int j=0;j<=i;j++){
                int x=j;
                int y=i-j;
                if(x>=n || y>=m) continue;
                v.push_back(mat[x][y]);
            }
            if(i%2==0) reverse(v.begin(), v.end());
            for(int i=0;i<v.size();i++) ans.push_back(v[i]);
        }
        return ans;
    }
};