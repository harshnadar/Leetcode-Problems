class Solution {
public:
    int n;
    int dp[2002];
    map<int, int> mp;
    map<pair<int,int>, bool> vis;
    
    bool solve(int i, int jump, vector<int>& stones){
        if(i>=n) return true;
        if(stones[i]+jump == stones[n-1]) return true;
        if(vis[{stones[i], jump}] == true) return false;
        vis[{stones[i],jump}]=true;
        if(mp.find(stones[i]+jump)!=mp.end()){
        return (solve(mp[stones[i]+jump],jump+1,stones) || solve(mp[stones[i]+jump],jump-1, stones) || solve(mp[stones[i]+jump], jump, stones));
        }
        return false;
    }
    bool canCross(vector<int>& stones) {
        n=stones.size();
        int sum = (n*(n+1))/2;
        
        if(stones[n-1]>sum) return false;
        if(stones[1]!=1) return false;
        
        for(int i=0;i<n;i++){
            mp[stones[i]]=i;
        }
        
        return solve(0,1,stones);
    }
};