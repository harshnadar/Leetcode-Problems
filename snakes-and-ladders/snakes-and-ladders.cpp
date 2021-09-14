class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int u=board.size();
        unordered_map<int,int> m;
        // vector<int> v(u*u+1);
        for(int i=u-1;i>=0;i--){
            if((u%2 && i%2==0) || (u%2==0 && i%2==1)){
                for(int j=0;j<u;j++){
                    if(board[i][j]!=-1){
                        m[u*(u-i-1)+j+1] = board[i][j];
                    }
                }
            }
            else{
                for(int j=u-1;j>=0;j--){
                    if(board[i][u-j-1]!=-1){
                        m[u*(u-i-1)+j+1] = board[i][u-j-1];
                    }
                }
            }
        }
        for(auto it: m) cout<<it.first<<" "<<it.second<<endl;
        // for(vector<int> &i : a)
        // {
        //     m[i[0]] = i[1];
        // }
        // for(vector<int> &i : b)
        // {
        //     m[i[0]] = i[1];
        // }
        queue<int> q;
        q.push(1);
        int level = 1;
        vector<bool> vis(u*u+1,0); 
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int x = q.front();
                q.pop();
                for(int i=1; i<7; i++)
                {
                    int finalpos = x+i;
                    if(m.count(x+i))
                    {
                        finalpos = m[x+i];
                    }
                    if(finalpos == u*u)
                    {
                        return level;
                    }
                    if(!vis[finalpos])
                    {
                        vis[finalpos] = 1;
                        q.push(finalpos);
                    }

                }
            }
            ++level;
        }
        return -1;
        // return 1;
    }
};