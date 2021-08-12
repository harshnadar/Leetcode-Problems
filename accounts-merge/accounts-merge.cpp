class Solution {
public:
    map<string, string> par;
    map<string, string> owner;
    
    map<string, set<string>> unions;
    
    string find(string a){
        if(par[a]==a) return a;
        return par[a]=find(par[a]);
    }
    
    void merge(string a, string b){
        par[b]=a;
    }
    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto it: accounts){
            for(int j=1;j<it.size();j++){
                par[it[j]]= it[j];
                owner[it[j]]=it[0];
            }
        }
        for(auto it: accounts){
            string p=find(it[1]);
            for(int j=2;j<it.size();j++){
                merge(p,find(it[j]));
            }
        }
        for(auto it: accounts){
            for(int j=1;j<it.size();j++){
                unions[find(it[j])].insert(it[j]);
            }
        }
        vector<vector<string> > res;
        for(auto p: unions){
            vector<string> emails(p.second.begin(), p.second.end());
            emails.insert(emails.begin(), owner[p.first]);
            res.push_back(emails);
        }
        return res;
    }
};