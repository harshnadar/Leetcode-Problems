class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n=heights.size();
        int m=heights[0].size();
        int dx[]={1,0,0,-1};
        int dy[]={0,1,-1,0};
        
        vector<vector<int> > dist(n, vector<int>(m,1e9));
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
        // queue<vector<int> > pq;
        pq.push({0,0,0});
        
        vector<int> v;
    
        while(!pq.empty()){
            int curx=pq.top()[1];
            int cury = pq.top()[2];
            int val = pq.top()[0];
         
            pq.pop();
            
            if(val>dist[curx][cury]) continue;
            
            if(curx==n-1 && cury==m-1) return val;
            
            for(int k=0;k<4;k++){
                int nx=curx+dx[k];
                int ny=cury+dy[k];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                int newDist = max(val,abs(heights[curx][cury] - heights[nx][ny]));
                
                if(dist[nx][ny]>newDist){
                    dist[nx][ny]=newDist;
                    pq.push({dist[nx][ny],nx,ny});
                }
            }          
        }
        return 0;
    }
};