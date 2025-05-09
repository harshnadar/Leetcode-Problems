class Solution {
public:
    int MOD = 1e9+7;
    double myPow(double x, int n) {
        if(n == 0) return 1;
        else if(n<0){
            return 1/x * myPow(1/x, -(n+1));
        }
        return (n%2==0)?myPow(x*x, n/2):x*myPow(x*x, n/2);
    }
};