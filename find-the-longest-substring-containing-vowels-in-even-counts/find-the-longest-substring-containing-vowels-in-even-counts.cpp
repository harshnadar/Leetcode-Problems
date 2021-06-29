class Solution {
public:
    int findTheLongestSubstring(string s) {
        int mask=0;
        map<int, int> m;
        int ans=0;
        m[0]=-1;
        int i=0;
        string v="aeiou";
        for(char c:s){
            for(int j=0;j<5;j++){
                if(c==v[j]){
                    mask^=(1<<(c-'a'));
                    break;
                }
            }
            if(m.find(mask)==m.end()) m[mask]=i;
            ans=max(ans, i-m[mask]);
            i++;
        }
        return ans;
    }
};