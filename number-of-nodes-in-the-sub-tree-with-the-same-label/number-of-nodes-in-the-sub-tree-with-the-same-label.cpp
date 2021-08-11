class Solution {
public:
    void dfs(int i, string& labels, vector<vector<int> >& al, int cnt[], vector<int>& res){
        if(res[i]==0){
            res[i]=1;
            for(auto it: al[i]){
                int cnt1[26]={};
                dfs(it, labels, al, cnt1, res);
                for(char j='a';j<='z';j++){
                    cnt[j-'a']+=cnt1[j-'a'];
                }
            }
            res[i]= ++cnt[labels[i]-'a'];
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> res(n);
        int cnt[26] = {};
        vector<vector<int>> al(n);
        for (auto &e : edges) {
            al[e[0]].push_back(e[1]);
            al[e[1]].push_back(e[0]);
        }
        dfs(0, labels, al, cnt, res);
        return res;
    }
};