class Solution {
public:
    int candy(vector<int>& A) {
        int n=A.size();
        vector<int> c(n,1);
        for(int i=1;i<n;i++){
            if(A[i-1]<A[i]) c[i]= c[i-1]+1;
        }
        for(int i=n-2;i>=0;i--){
            if(A[i+1]<A[i]) c[i]=max(c[i+1]+1, c[i]);
        }
        return accumulate(c.begin(), c.end(), 0);
    }
};