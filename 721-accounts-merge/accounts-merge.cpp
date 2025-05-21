class Solution {
public:
    map<string, string> par;
    map<string, string> owner;
    map<string, set<string> > unions;

    string find(string a){
        if(par[a] == a) return a;
        return par[a] = find(par[a]);
    }

    void merge(string a, string b){
        par[b] = a;
    }


    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        for(auto it: accounts){
            for(int i = 1; i<it.size(); i++){
                par[it[i]] = it[i];
                owner[it[i]] = it[0];
            }
        }
        for(auto it: accounts){
            string p = find(it[1]);
            for(int i=2;i<it.size();i++){
                merge(p, find(it[i]));
            }
        }

        for(auto it: accounts){
            for(int i=1;i<it.size();i++){
                unions[find(it[i])].insert(it[i]);
            }
        }

        vector<vector<string> > ans;
        for(auto it: unions){
            vector<string> temp;
            temp.push_back(owner[it.first]);
            for(auto itr: it.second) temp.push_back(itr);
            ans.push_back(temp);
        }
        return ans;

    }
};