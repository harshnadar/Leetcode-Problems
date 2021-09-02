class Solution {
public:
    int distinctSubseqII(string s) {
        long long int ends[26]={0};
        int mod=1e9+7;
        for(char c: s){
            ends[c-'a'] = accumulate(ends, ends+26,(long long)1)%mod;
        }
        int ans= accumulate(ends, ends+26,(long long)0)%mod;
        return ans;
    }
};