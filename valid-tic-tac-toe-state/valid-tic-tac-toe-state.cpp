class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        bool wony = false, wonx = false;
    int rows = board.size();
    int cols = rows ? board[0].size() : 0;
    int diax = 0, diay = 0, xdiax = 0, xdiay = 0, x_count = 0, y_count = 0;
    
    for(int i = 0; i < rows; i++) {
        int rowsx = 0, rowsy = 0;
        int colsx = 0, colsy = 0;
        for(int j = 0; j < cols; j++) {
            // see current row
            if(board[i][j] == 'X')
                rowsx++,x_count++;
            if(board[i][j] == 'O')
                rowsy++, y_count++;
            // see ith column
            if(board[j][i] == 'X')
                colsx++;
            if (board[j][i] == 'O')
                colsy++;
        }
        
        // see both the diagonals
        if(board[i][i] == 'X')
            diax++;
        if(board[i][i] == 'O')
            diay++;
        if(board[i][cols - 1 - i] == 'X')
            xdiax++;
        if(board[i][cols - 1 - i] == 'O')
            xdiay++;
        
        if(rowsx == 3 || colsx == 3 || diax == 3 || xdiax == 3)
            wonx = true;
        
         if(rowsy == 3 || colsy == 3 || diay == 3 || xdiay == 3)
            wony = true;
    }
    
    if(!(x_count == y_count || x_count == y_count + 1))
        return false;
    
    if((wonx && wony) || (wonx && x_count == y_count) || (wony && x_count != y_count))
        return false;
    
    return true;
    }
};