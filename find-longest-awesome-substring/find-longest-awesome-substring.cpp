class Solution {
public:
    int longestAwesome(string s) {
        int n=s.size();
        int mask=0;
        vector<int> m(1025,n);
        m[0]=-1;
        long long int ans=0;
        int i=0;
        for(int i=0;i<n;i++){
            mask^=(1<<(s[i]-'0'));
            ans=max(ans, (long long)(i-m[mask]));
            for(int j=0;j<10;j++){
                ans=max(ans, (long long)(i-m[mask^(1<<j)]));
            }
            m[mask]=min(m[mask],i);
        }
        return ans;
    }
};