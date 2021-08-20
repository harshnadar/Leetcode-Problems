int dx[]= {1,0,0,-1};
int dy[]= {0,1,-1,0};

class Solution {
public:
    int par[50005];
    vector<vector<int> > g;
    int sz[50005];
    int row, col;
    
    int find(int a){
        if(par[a]==a) return a;
        return par[a]=find(par[a]);
    }
    
    void uni(int a, int b){
        a=find(a);
        b=find(b);
        if(a!=b){
            par[a]=b;
            sz[b]+=sz[a];
        }
    }
    
    int index(int i, int j){
        return col*i+j+1;
    }
    
    void uniAll(int curRow, int curCol){
        int curMark = index(curRow, curCol);
        
        for(int k=0;k<4;k++){
            int newRow= curRow+dx[k];
            int newCol = curCol+dy[k];
            int newMark = index(newRow, newCol);
            if(newRow<0 || newCol<0 || newRow>=row || newCol>=col || g[newRow][newCol]!=1) continue;
            uni(curMark, newMark);
        }
        
        if(curRow==0){
            uni(0,curMark);
        }
    }
    
    
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        row = grid.size();
        col = grid[0].size();
        this->g = grid;
        
        for(int i=0;i<row*col+1;i++){
            par[i]=i;
            sz[i]=1;
        }
        
        for(auto hit: hits){
            if(g[hit[0]][hit[1]]==1) g[hit[0]][hit[1]]=2;
        }
        
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(g[i][j]==1){
                    uniAll(i,j);
                }
            }
        }
        
        int presentRemaining = sz[find(0)];
        cout<<presentRemaining<<"\n";
        int i=hits.size()-1;
        vector<int> bricks(hits.size());
        
        while(i>=0){
            int x= hits[i][0];
            int y= hits[i][1];
            if(g[x][y]==2){
                g[x][y]=1;
                uniAll(x,y);
                int newRemaining=  sz[find(0)];
                cout<<newRemaining<<"\n";
                bricks[i] = max(newRemaining - presentRemaining -1, 0);
                presentRemaining = newRemaining;
            }
            i--;
        }
        return bricks;
    }
};