class Solution {
public:
    vector<string> neigh(string s){
        vector<string> res;
        for(int i=0;i<4;i++){
            for(int diff=-1;diff<=1;diff+=2){
                string tmp=s;
                tmp[i]=(tmp[i]-'0'+diff+10)%10 +'0';
                res.push_back(tmp);
            }
        }
        return res;
    }
    
    int openLock(vector<string>& dead, string target) {
        unordered_set<string> deads(dead.begin(), dead.end());
        if(deads.find("0000")!=deads.end()) return -1;
        queue<string>q;
        q.push("0000");
        int d=0;
        while(!q.empty()){
            d++;
            int n=q.size();
            for(int i=0;i<n;i++){
                string cur = q.front();
                q.pop();
                if(cur==target) return d-1;
                for(auto it: neigh(cur)){
                    cout<<it<<"\n";
                    if(deads.find(it)!=deads.end()) continue;
                    deads.insert(it);
                    q.push(it);
                }
            }
        }
        return -1;
    }
};