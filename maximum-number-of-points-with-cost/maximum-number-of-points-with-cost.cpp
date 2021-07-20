#define f(a,b,i) for(int i=a;i<b;i++)
#define ll long long int
class Solution {
public:
    ll maxPoints(vector<vector<int>>& p) {
        ll n=p.size();
        ll m=p[0].size();
        vector<ll> prev(m);
        f(0,m,i) prev[i]=p[0][i];
        f(1,n,i){
            vector<ll> right(m,0), left(m,0), cur(m,0);
            left[0]=prev[0];
            f(1,m,j){
                left[j]=max(left[j-1]-1, prev[j]);
            }
            right[m-1]=prev[m-1];
            for(int j=m-2;j>=0;j--){
                right[j]=max(right[j+1]-1,prev[j]);
            }
            f(0,m,j){
                cur[j]=p[i][j]+max(left[j],right[j]);
            }
            prev=cur;
        }
        return *max_element(begin(prev), end(prev));
    }
};