int dx[]={-1,0,1,1,1,0,-1,-1};
int dy[]={1,1,1,0,-1,-1,-1,0};
class Solution {
public:
    int n; int m;
    bool isValid(int i, int j){
        if(i<0 || i>=n || j<0 || j>=m) return false;
        return true;
    }
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int> > prev = board;
        n=board.size();
        m=board[0].size();
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<m;j++){
//                 cout<<prev[i][j]<<" ";
//             }
//             cout<<endl;
//         }
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int l=0;
                for(int k=0;k<8;k++){
                    int u=i+dx[k];
                    int v=j+dy[k];
                    if(isValid(u,v) && prev[u][v]){
                        l++;
                    }
                }
                if(l<2 || l>3) board[i][j]=0;
                else if(l==3) board[i][j]=1;
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<bpar
        //     }
        // }
        // return board;
    }
};