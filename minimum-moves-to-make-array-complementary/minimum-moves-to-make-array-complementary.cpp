class Solution {
public:
    const int N = 100000;
    int minMoves(vector<int>& nums, int limit) {
        vector<int> dT(2 * N + 1, 0);   // dT[i] = T[i] - T[i-1]
        
        int n = nums.size(), res = INT_MAX;
        for (int i = 0; i < n / 2; ++i) {
            int a = nums[i], b = nums[n-1-i];
            
            dT[2] += 2;
            dT[min(a, b) + 1] -= 1; 
            dT[a + b] -= 1;
            dT[a + b + 1] += 1;
            dT[max(a, b) + limit + 1] += 1;
        }
        
        int curr = 0;
        for (int t = 2; t <= limit * 2; ++t) {
            curr += dT[t];
            res = min(res, curr);
        }
        return res;
    }
};