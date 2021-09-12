class Solution {
public:
    int mx = 0;
    int maxProduct(string s) {
        
        // char[] c = s.toCharArray();
        string s2,s1;
        dfs(s, 0, s1, s2);
        
        return mx;
    }
    
    void dfs(string& c, int i, string& s1, string& s2){
        
        if(i >= c.size()){
            
            if(isPalin(s1) && isPalin(s2)){
                int u = s1.size()*s2.size();
                mx = max(mx, u);
            }
            return;
        }
        s1.push_back(c[i]);
        dfs(c, i+1, s1, s2);
        s1.pop_back();
        
        s2.push_back(c[i]);
        dfs(c, i+1, s1, s2);
        s2.pop_back();
        
        dfs(c, i+1, s1, s2);
    }
    
     bool isPalin(string& str){
 
        int i = 0, j = str.size() - 1;
 
        while (i < j) {
 
            if (str[i] != str[j])
                return false;
            i++;
            j--;
        }
 
        return true;
    }
};