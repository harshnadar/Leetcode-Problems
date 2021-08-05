class Solution {
public:
    // map<char, vector<char> adj;
    map<int, int> par;
    
    int find(int a){
        if(par[a]==a) return a;
        return par[a]=find(par[a]);
    }
    
    void uni(int a, int b){
        a=find(a);
        b=find(b);
        // if(a>b) swap(a,b);
        par[a]=b;
    }
    
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        // map<char, bool> mp;
        for(int i=0;i<26;i++) par[i]=i;
        for(auto s: equations){
            char u=s[0];
            char v=s[3];
            if(s[1]=='='){
                uni(u-'a',v-'a');
            }
        }
        for(auto s: equations){
            char u=s[0];
            char v=s[3];
            if(s[1]=='!' && find(u-'a')==find(v-'a')) return false;
        }
        return true;
    }
};