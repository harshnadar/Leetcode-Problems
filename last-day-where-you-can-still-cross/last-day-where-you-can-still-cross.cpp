class Solution {
public:
    
    int par[20005];
    
    int find(int a){
        if(par[a]==-1) return a;
        return par[a]=find(par[a]);
    }
    
    void uni(int a, int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        par[b]=a;
    }
    
    int index(int col, int i, int j){
        return col*i+j+1;
    }
    
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        bool isLand[row+1][col+1];
        memset(isLand, false, sizeof isLand);
        for(int i=0;i<20005;i++){
            par[i]=-1;
        }
        int dx[]={1,0,0,-1};
        int dy[]={0,-1,1,0};
        
        for(int i=cells.size()-1;i>=0;i--){
            int curRow = cells[i][0]-1;
            int curCol = cells[i][1]-1;
            
            isLand[curRow][curCol]=true;
            
            for(int j=0;j<4;j++){
                int nextRow = curRow + dx[j];
                int nextCol = curCol + dy[j];
                // cout<<nextRow<<" "<<nextCol<<"\n";
                
                if(nextRow<0 || nextCol<0 || nextRow>=row || nextCol>=col || !isLand[nextRow][nextCol]) continue;
                // if() continue;
                
                int s1=index(col,curRow,curCol);
                int s2=index(col, nextRow, nextCol);
                
                uni(s1,s2);
            }
            
            if(curRow==0){
                uni(0,index(col,curRow,curCol));
            }
            else if(curRow==row-1){
                uni(row*col+1,index(col,curRow,curCol));
            }
            
            if(find(0)==find(row*col+1)) return i;
        }
        
        return 0;
    }
};