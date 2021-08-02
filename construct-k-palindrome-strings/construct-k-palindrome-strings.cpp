class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();
        if(k>n) return false;
        else if( k==n) return true;
        int odd=0; int cnt[26];
        memset(cnt,0, sizeof cnt);
        for(int i=0;i<n;i++){
            cnt[s[i]-'a']^=1;
            odd+= cnt[s[i]-'a']>0 ? 1: -1;
        }
        return odd<=k;
    }
};