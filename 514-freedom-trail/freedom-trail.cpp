class Solution {
public:
    vector<vector<int> > mp;
    int dp[102][102];
    int n,m;

    int solve(string key, int i, int j){
        if(i>=m) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int a = 1e5;
        for(int k = 0;k<mp[key[i]-'a'].size();k++){
            a = min(a, min({abs(mp[key[i]-'a'][k] - j), n - j + mp[key[i]-'a'][k], n - mp[key[i] - 'a'][k] + j}) + solve(key, i+1, mp[key[i] - 'a'][k]));
        }
        return dp[i][j] = a;
    }

    int findRotateSteps(string ring, string key) {
        this->n = ring.size();
        this->m = key.size();
        mp.resize(26);
        for(int i=0;i<n;i++){
            mp[ring[i]-'a'].push_back(i);
        }
        memset(dp,-1,sizeof dp);
        
        int a = solve(key, 0,0) + key.size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return a;
    }
};