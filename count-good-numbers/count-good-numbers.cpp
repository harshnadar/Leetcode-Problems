class Solution {
public:
    int mod=1e9+7;
    
    long long int pw(long long int a, long long int p){
        long long int result=1;
        while(p>0){
            if(p&1) result=((a%mod)*(result%mod))%mod;
            a=(a*a)%mod;
            p>>=1;
        }
        return result%mod;
    }
    
    int countGoodNumbers(long long n) {
        
        long long int x= n/2 + n%2;
        long long int y=n/2;
        long long int ans= ((pw(5,x)%mod)*(pw(4,y)%mod))%mod;
        return (int)ans%mod;
    }
};