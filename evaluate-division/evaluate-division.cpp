class Solution {
    map<string, vector<pair<string, double> > > m;
    set<string> vis;
    double ans=-1.0;
    //double temp=1.0;
    vector<double>res;
    
public:
    void dfs(string a, string b, double temp){
        if(vis.find(a)!=vis.end()) return;
        else{
            vis.insert(a);
            if(a==b){
                ans=temp;
                return;
            }
            else{
                for(auto it:m[a]){
                    
                    dfs(it.first,b, temp*it.second);
                }
            }
        }
        
    }
    
    vector<double> calcEquation(vector<vector<string>>& e, vector<double>& v, vector<vector<string>>& q) {
        for(int i=0;i<e.size();i++){
            m[e[i][0]].push_back({e[i][1],v[i]});
            m[e[i][1]].push_back({e[i][0],1/v[i]});
        }
        for(int i=0;i<q.size();i++){
            string a=q[i][0];
            string b=q[i][1];
            ans=-1.0;
            vis.clear();
            if(m.find(a)!=m.end())
            dfs(a,b, 1.0);
            res.push_back(ans);
        }
        return res;
    }
};