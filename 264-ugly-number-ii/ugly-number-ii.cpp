class Solution {
public: 
    int nthUglyNumber(int n) {
        set<long long int> s;
        s.insert(1);
        if(n==1) return 1;
        int count = 1;
        while(count<=n){
            long long int a = *s.begin();
            s.erase(s.begin());
            if(count == n) return (int)a;
            s.insert(a*2);
            s.insert(a*3);
            s.insert(a*5);
            count++;
        }
        return 1;
    }
};