class Solution {
public:
    int numSplits(string s) {
        int n = s.size();
        if(n==1) return 0;
        if(n==2) return 1;
        int ans = 0;
        unordered_set<char> st1, st2;
        vector<int> pre(n,0), suf(n,0);
        for(int i=0;i<n;i++){
            st1.insert(s[i]);
            pre[i] = st1.size();
            st2.insert(s[n-i-1]);
            suf[n-i-1] = st2.size();
        }
        for(int i=0;i<n-1;i++){
            if(pre[i] == suf[i+1]) ans++;
        }
        return ans;
    }
};