class Solution {
public:
    
    vector<vector<int> > floyd(vector<vector<int> >& graph){
        int v=graph.size();
        vector<vector<int> > dist(graph);
        for(int k=0;k<v;k++){
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    dist[i][j]=min(dist[i][j], dist[i][k]+dist[k][j]);
                }
            }
        }
        return dist;
    }
    
    int findTheCity(int n, vector<vector<int>>& edges, int threshold) {
        vector<vector<int> > graph(n+1, vector<int>(n+1, 1e6));
        for(auto it: edges){
            graph[it[0]][it[1]]=it[2];
            graph[it[1]][it[0]]=it[2];
        }
        vector<vector<int> > dist= floyd(graph);
        int mn=INT_MAX;
        int ans=-1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<dist[i][j]<<" ";
            }
            cout<<"\n";
        }
        for(int i=0;i<n;i++){
            int count=0;
            for(int j=0;j<n;j++){
                if(i!=j && dist[i][j]<=threshold){
                    count++;
                }
            }
            if(count<=mn){
                ans=i; mn=count;
            }
        }
        return ans;
    }
};