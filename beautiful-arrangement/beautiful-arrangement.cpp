class Solution {
public:
    bool vis[16];
    void solve(int i, int n, int& count){
        if(i>n) count++;
        for(int j=1;j<=n;j++){
            if(!vis[j] && (j%i==0 || i%j ==0)){
                vis[j]=true;
                solve(i+1,n,count);
                vis[j]=false;
            }
        }
        
    }
    int countArrangement(int n) {
        int count=0;
        solve(1,n,count);
        return count;
    }
};