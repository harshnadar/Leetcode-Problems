class Solution {
public:
    bool check(int n){
        vector<int> v;
        vector<int> x;
        for(int i=n;i>0;i/=10){
            int u=i%10;
            if(u==3 || u==4 || u==7) return false;
            if(u==0 || u==1 || u==8) {v.push_back(u); x.push_back(u);continue;}
            else if(u==2) {v.push_back(5); x.push_back(u);}
            else if(u==5) {v.push_back(2); x.push_back(u);}
            else if(u==6) {v.push_back(9); x.push_back(u);}
            else if(u==9) {v.push_back(6); x.push_back(u);}
        }
        return !(x==v);
    }
    int rotatedDigits(int n) {
        if(n==1) return 0;
        int count=0;
        for(int i=1;i<n+1;i++){
            if(check(i)) count++;
        }
        return count;
    }
};