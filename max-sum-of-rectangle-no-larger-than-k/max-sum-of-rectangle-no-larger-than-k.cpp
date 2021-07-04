#define f(a,b,i) for(int i=a;i<b;i++)

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        int n=matrix.size();
        int m=matrix[0].size();
        int maxx=INT_MIN;
        f(0,n,i){
            vector<int> sum(m);
            f(i,n,j){
                f(0,m,k){
                    sum[k]+=matrix[j][k];
                }
                set<int> cur;
                cur.insert(0);
                int cursum=0;
                f(0,m,k){
                    cursum+=sum[k];
                    auto it= cur.lower_bound(cursum-K);
                    if(it!=cur.end()){
                        maxx=max(maxx, cursum-*it);
                    }
                    cur.insert(cursum);
                }
            }
        }
        return maxx;
    }
};