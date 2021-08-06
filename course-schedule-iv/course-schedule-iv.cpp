class Solution {
public:
    vector<vector<int>> floyd(vector<vector<int>>& graph){
        vector<vector<int> > dist(graph);
        int v=graph.size();
        for(int k=0;k<v; k++){
            for(int i=0;i<v;i++){
                for(int j=0;j<v;j++){
                    dist[i][j]=min(dist[i][j], dist[i][k]+ dist[k][j]);
                }
            }
        }
        return dist;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        vector<vector<int> > graph(numCourses, vector<int>(numCourses, 1e5));
        for(auto it: prerequisites){
            graph[it[0]][it[1]]=1;
        }
        vector<vector<int> > dist = floyd(graph);
        vector<bool> ans;
        for(auto it: queries){
            if(dist[it[0]][it[1]]<1e5) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};