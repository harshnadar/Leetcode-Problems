class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n=s.size();
        int m=part.size();
        string ans;
        ans=s;
        
        if(ans.find(part)== string::npos) return ans;
        while(ans.find(part)!=string::npos){
            int x=ans.find(part);
            ans=(ans.substr(0,x) + ans.substr(x+m));
            // cout<<ans<<'\n';
        }
        return ans;
    }
};