int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

class Solution {
public:
    int n,m;
    bool vis1[201][201];
    int vis2[201][201];
    
    bool isValid(int i, int j){
        if(i>=n || i<0 || j>=m || j<0) return false;
        return true;
    }
    
    void dfs1(int i, int j, vector<vector<char> >& board){
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(board[i][j]=='X') return;
        vis1[i][j]=true;
        board[i][j]='#';
        for(int k=0;k<4;k++){
            if(isValid(i+dx[k], j+dy[k]))
            if(vis1[i+dx[k]][j+dy[k]]==false){
                dfs1(i+dx[k], j+dy[k], board);
            }
        }
    }
    
    void dfs2(int i, int j, vector<vector<char> >& board){
        if(i<0 || i>=n || j<0 || j>=m) return;
        if(board[i][j]=='X' || board[i][j]=='#') return;
        vis2[i][j]=true;
        board[i][j]='X';
        for(int k=0;k<4;k++){
            if(vis2[i+dx[k]][j+dy[k]]==false){
                dfs2(i+dx[k], j+dy[k], board);
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O'){
                dfs1(i,0,board);
            }
            if(board[i][m-1]=='O'){
                dfs1(i,m-1,board);
            }
        }
        for(int i=0;i<m;i++){
            if(board[0][i]=='O'){
                dfs1(0,i,board);
            }
            if(board[n-1][i]=='O'){
                dfs1(n-1,i,board);
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(vis2[i][j]==false && board[i][j]=='O'){
                    dfs2(i,j,board);
                }
            }
        }
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='#') board[i][j]='O';
                cout<<board[i][j]<<" ";
            }
            cout<<"\n";
        }
        
    }
};