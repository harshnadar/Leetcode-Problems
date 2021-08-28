int dx[]={1,0,0,-1};
int dy[]={0,1,-1,0};
class Solution {
public:
    int n, m;
    int getFlip(int i, int j, int mask){
        int pos=m*n-1-i*m-j;
        cout<<i<<" "<<j<<" "<<pos<<endl;
        // cout<<pos<<endl;
        mask^=(1<<pos);
        for(int k=0;k<4;k++){
            int x=i+dx[k];
            int y=j+dy[k];
            if(x>=0 && x<n && y>=0 && y<m){
                pos = m*n-1-x*m-y;
                mask^=(1<<pos);
            }
        }
        return mask ;
    }

    int minFlips(vector<vector<int>>& mat) {
        n = mat.size();
        m=mat[0].size();
       
        cout<<"Value of n and m "<<n<<" "<<m<<endl;
        int bitvec = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bitvec<<=1;
                bitvec|=mat[i][j];
            }
        }
        if(!bitvec) return 0;

        queue<int> q;
        q.push(bitvec);
        int dist=0;
        unordered_set<int> vis;

        while(!q.empty()){
            int u=q.size();
            for(int i=0;i<u;i++){
                int cur = q.front();
                q.pop();
                if(!cur) return dist;

                for(int i=0;i<n;i++){
                    for(int j=0;j<m;j++){
                        if(i<n && j<m) bitvec = getFlip(i,j,cur);
                        if(!vis.count(bitvec)){
                            q.push(bitvec);
                            vis.insert(bitvec);
                        }
                    }
                }
            }
            dist++;
        }
        return -1;
    }
};