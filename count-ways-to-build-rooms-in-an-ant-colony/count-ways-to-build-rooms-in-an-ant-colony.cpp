class Solution {
public:
    const int mod = 1e9+7;
    vector<int> adj[100002];
    
    long long int dfs(int node, vector<long long int>& sz){
        long long int ans=1;
        
        for(auto it: adj[node]){
            ans+=dfs(it,sz);
        }
        sz[node]=ans;
        return ans;
    }
    
    int power(long long int a){
        int p=mod-2;
        long long int res=1;
        while(p>0){
            if(p&1){
                res = (a*res)%mod;
            }
            a=(a*a)%mod;
            p>>=1;
        }
        
        return res;
    }
    
    int modInverse(long long int a){
        return power(a);
    }
    
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n=prevRoom.size();
        for(int i=1;i<n;i++){
            adj[prevRoom[i]].push_back(i);
        }
        vector<long long int> sz(n);
        dfs(0,sz);
        
        long long int nFact=1;
        for(int i=2;i<=n;i++){
            nFact = (nFact*i)%mod;
        }
        
        long long int den = 1;
        for(int i=0;i<n;i++){
            den = (den*sz[i])%mod;
        }
        
        int invDen = modInverse(den);
        
        int ans = (nFact*invDen)%mod;
        
        return ans;
    }
};