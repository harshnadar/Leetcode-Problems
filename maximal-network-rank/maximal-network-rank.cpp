class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> in(n,0);
        map<pair<int,int>, int> mp;
        for(auto it: roads){
            in[it[0]]++;
            in[it[1]]++;
            mp[{it[0], it[1]}]++;
        }
        // sort(in.begin(), in.end());
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                ans = max(ans, in[i]+in[j]-((mp[{i,j}]>0) || (mp[{j,i}]>0)));
            }
        }
        return ans;
    }
};