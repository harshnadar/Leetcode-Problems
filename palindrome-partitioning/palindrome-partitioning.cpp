class Solution {
public:
    vector<vector<string>> ans;
    
    unordered_map<string, bool>M;
    
    bool check(string &t)
    {
        string x= t;
        reverse(x.begin(), x.end());
        return M[t]=(x==t);
    }
    
    void partHelp(int strt, string &s, vector<string>&V)
    {
        if(strt == s.size())
        {
            ans.push_back(V);
            return;
        }
        string t = "";
        for(int i=strt; i<s.size(); i++)
        {
            t += s[i]; 
            if(M.find(t) != M.end())
            {
                if(M[t])
                {
                    V.push_back(t);
                    partHelp(i+1, s, V);
                    V.pop_back();
                }
            }
            else
            {
                if(check(t))
                {
                    V.push_back(t);
                    partHelp(i+1, s, V);
                    V.pop_back();
                }
            }
        }
    }
    vector<vector<string>> partition(string s) {
        
        vector<string>V;
        partHelp(0, s, V);
        
        return ans;
    }
};