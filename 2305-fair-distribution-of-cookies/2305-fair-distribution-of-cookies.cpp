class Solution {
public:
    int ans = 1e9;
    int n;
    vector<int> dist;
    int k;
    
    void solve(vector<int>& cookies, int i){
        if(i==n){
            int x=-1;
            for(int u=0;u<k;u++){
                x = max(x, dist[u]);
            }
            ans = min(ans, x);
            return;
        }
        for(int j=0;j<k;j++){
            dist[j]+=cookies[i];
            solve(cookies, i+1);
            
            dist[j]-=cookies[i];
        }
        
        return;
    }
    
    int distributeCookies(vector<int>& cookies, int k) {
        sort(cookies.begin(), cookies.end(), greater<int>());
        int sum = accumulate(cookies.begin(), cookies.end(),0);
        dist.resize(k);
        n = cookies.size();
        this->k=k;
        
        solve(cookies, 0);
        return ans;
    }
};