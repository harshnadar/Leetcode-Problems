class Solution {
public:
    
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        
        int cur = 0, res = 0, count[] = {1, 0}, mod = (int)1e9 + 7;
        for (int a: arr) {
            cur ^= a & 1;
            res = (res + count[1 - cur]) % mod;
            count[cur]++;
        }
        return res;
        
    }
};