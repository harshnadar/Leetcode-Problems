class Solution {
public:
    int findSum(int x, int m, int n){
        int i=m, j=1;
        int count =0;
        while(i>=1 && j<=n){
            if(i*j<=x){
                count+=i;
                j++;
            }
            else i--;
        }
        return count;
    }
    
    int findKthNumber(int m, int n, int k) {
        int lo = 1; int hi = n*m;
        while(lo<hi){
            int mid = lo+(hi-lo)/2;
            int val = findSum(mid, m,n);
            if(val<k){
                lo=mid+1;
            }
            else hi=mid;
        }
        return lo;
    }
};