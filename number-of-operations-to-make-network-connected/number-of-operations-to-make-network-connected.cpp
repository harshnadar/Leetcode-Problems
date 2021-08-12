class Solution {
public:
    int par[100002];
    
    int find(int a){
        if(par[a]==-1) return a;
        return par[a]=find(par[a]);
    }
    
    void union_set(int a, int b){
        par[b]=a;
    }
    
    int makeConnected(int n, vector<vector<int>>& connections) {
        memset(par,-1,sizeof par);
        // vector<pair<int, int> > ans;
        int count=0;
        for(auto it: connections){
            int a = it[0];
            int b=it[1];
            int s1 = find(a);
            int s2 = find(b);
            if(s1!=s2){
                union_set(s1,s2);
            }
            else{
                count++;
                // ans.push_back({a,b});
            }
        }
        set<int> s;
        for(int i=0;i<n;i++){
           s.insert(find(i));
        }
        if(s.size()-1<=count) return s.size()-1; 
        return -1;
    }
};