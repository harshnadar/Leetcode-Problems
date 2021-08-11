class Solution {
public:
    int n,m;
    
    bool dfs(int i, int j, int pre, string word, vector<vector<char>>& board){
        if(pre == word.size()) return true;
        if(i<0 || i>=n || j<0 || j>=m || word[pre]!=board[i][j]) return false;
        char ch=board[i][j];
        board[i][j]='*';
        bool ret =dfs(i+1,j,pre+1,word,board) || dfs(i-1,j,pre+1,word,board) || dfs(i,j+1,pre+1,word,board) || dfs(i,j-1,pre+1,word,board);
        board[i][j]=ch;
        return ret;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        vector<pair<int, int> > v;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(word[0]==board[i][j]){
                    v.push_back({i,j});
                }
            }
        }
        for(auto it: v){
            vector<vector<int> > vis(n,vector<int>(m,0));
            if(dfs(it.first, it.second, 0, word, board)) return true;
        }
        return false;
    }
};