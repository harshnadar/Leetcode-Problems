class Solution {
public:
    int stoneGameVI(vector<int>& a, vector<int>& b) {
        int n=a.size();
        int diff=0;
        for(int i=0;i<n;i++){
            a[i]+=b[i];
            diff-=b[i];
        }
        sort(a.begin(), a.end());
        for(int i=n-1;i>=0;i-=2){
            diff+=a[i];
        }
        return ((diff==0)?0:(diff>0)?1:-1);
    }
};