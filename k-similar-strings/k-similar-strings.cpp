class Solution {
public:
    
    int kSimilarity(string s1, string s2) {
        unordered_set<string> s;
        int n=s1.size();
        if(s1==s2) return 0;
        queue<pair<string, int> > q;
        int i=0;
        for(;i<n;i++){
            if(s1[i]!=s2[i]) break;
        }
        q.push({s1,i});
        unordered_set<string> vis;
        vis.insert(s1);
        int d=0;
        while(!q.empty()){
            d++;
            int x=q.size();
            for(int i=0;i<x;i++){
                string cur = q.front().first;
                int idx = q.front().second;
                q.pop();
                cout<<cur<<"\n";
                if(cur == s2) return d-1;
                
                while(cur[idx] == s2[idx]) idx++;
                // cout<<idx<<"\n";
                
                for(int i = idx +1; i < n; ++i) {
                    if(cur[i] == s2[idx] && cur[i] != s2[i]) {
                        swap(cur[idx], cur[i]);
                        
                        if(vis.count(cur) == 0) {
                            q.push({cur, idx+1});
                            vis.insert(cur);
                        }
                        
                        swap(cur[idx], cur[i]);
                    }
                }                
                
            }
        }
        return 1;
    }
};