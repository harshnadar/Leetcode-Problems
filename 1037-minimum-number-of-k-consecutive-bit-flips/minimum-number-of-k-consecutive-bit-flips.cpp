class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> freq(n + 1, 0);  
        int count = 0;               
        int ans = 0;                 

        for (int i = 0; i < n; ++i) {
            count += freq[i];  
            if ((nums[i] + count) % 2 == 0) {
               
                if (i + k > n) {
                    return -1;
                }
                ans++;               
                freq[i]++;           
                freq[i + k]--;       
                count++;             
            }
        }

        return ans;
    }
};