class Solution {
public:
    
    int m, n;
    vector<int> a;
    vector<int> b;
    vector<vector<int> > dp;
    
    bool solve(int idx, int mask) {
        if(mask == (1 << m) - 1)
            return 1;
        
        if(idx == n)
            return 0;
        
        if(dp[idx][mask] != -1)
            return dp[idx][mask];
        
        bool ans = solve(idx + 1, mask);
        
        for(int i = 0; i < (1 << m); i++) {
            if(mask != (mask & (i))) continue;
            int nm = mask;
            int sum = 0;
            for(int j = 0; j < m; j++) {
                if(mask&(1<<j)) continue;
                if(i&(1 << j)) {
                    sum += b[j];
                    nm |= (1 << j);    
                }
            }
            if(sum <= a[idx])
                ans |= solve(idx + 1, nm);
        }
        
        return dp[idx][mask] = ans;
    }
    
    
    bool canDistribute(vector<int>& nums, vector<int>& b) {
        
        unordered_map<int, int> mp;
        for(int x: nums) {
            mp[x] += 1;
        }
        for(auto p: mp)
            a.push_back(p.second);
        
        this->b = b;
        this->m = b.size();
        this->n = a.size();
        dp.clear(); dp.resize(n, vector<int> ((1<<m), -1));
        
        return solve(0, 0);
    }
};