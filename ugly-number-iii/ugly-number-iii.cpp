class Solution {
public:
    bool func(long long int mid, int n, long long int a, long long int b, long long int c){
        long long int ab = (a*b)/__gcd(a,b);
        long long int bc = (b*c)/__gcd(b,c);
        long long int ac = (a*c)/__gcd(a,c);
        
        long long int abc = (a*bc)/__gcd(a,bc);
        
        long long int total = mid/a + mid/b + mid/c -mid/ab - mid/ac - mid/bc + mid/abc;
        return total>=n;
    }
    
    int nthUglyNumber(int n, long long int a, long long int b, long long int c) {
        
        long long int lo=1, hi=1e10;
        
        while(lo<hi){
            long long int mid = lo + (hi-lo)/2;
            
            if(func(mid,n,a,b,c)) hi=mid;
            else lo=mid+1;
        }
        
        return lo;
    }
};