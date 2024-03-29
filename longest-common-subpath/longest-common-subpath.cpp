class Solution {
public:
    const long long p = 100006;
    const long long mod = 1e11+7;
    long long n,m;
    
    bool check (vector<vector<int>>&paths, int len)
    {
        if(len==0) return true;
        map<long long, int> freq;
        for(int i=0;i<m;i++)
        {
            long long curr_hash = 0, pow = 1;
            set<long long> found_hashes;
            for(int j=0;j<len;j++)
            {
                curr_hash = (curr_hash*p)%mod;
                curr_hash += paths[i][j];
                if(j!=len-1)pow = (pow*p)%mod;
            }
            found_hashes.insert(curr_hash);
            for(int j=len;j<paths[i].size();j++)
            {
                curr_hash += mod;
                curr_hash -= (paths[i][j-len] * pow)%mod;
                curr_hash %= mod;
                curr_hash = curr_hash*p;
                curr_hash %= mod;
                curr_hash += paths[i][j];
                curr_hash %= mod;
                found_hashes.insert(curr_hash);
            }
            while(found_hashes.size())
            {
                long long h = *(found_hashes.begin());
                found_hashes.erase(found_hashes.begin());
                freq[h]++;
                if(freq[h]==m) return true;
            }
            
        }
        return false;
    }
    
    int longestCommonSubpath(int elements, vector<vector<int>>& paths) {
        n = elements;
        m = paths.size();
        int minlen = INT_MAX;
        for(int i=0;i<paths.size();i++)
        {
            minlen = min(minlen,(int)paths[i].size());
        }
        int start = 0, end = minlen, mid = 0;
        while(start<=end)
        {
            int mid = (start+end)/2;
            if(check(paths,mid))
            {
                start = mid + 1;
            }
            else
            {
                end = mid - 1;
            }
        }
        return end;
    }
};
