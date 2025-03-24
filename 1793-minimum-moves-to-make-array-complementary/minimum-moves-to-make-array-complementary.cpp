class Solution {
public:
    int N = 3*1e5;

    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> freq(N, 0);
        for(int i =0;i<n/2;i++){
            int a = nums[i], b = nums[n-i-1];
            int start = 2;
            int lo = min(a,b) + 1;
            int mi = a+b;
            int hi = max(a,b) + limit;
            int end = 2*limit;

            freq[start]+=2;
            freq[lo] -=1;
            freq[mi] -=1;
            freq[mi+1] +=1;
            freq[hi+1] +=1;
        }
        int temp = 0;
        int ans = 1e6;
        for(int i=2;i<=2*limit;i++){
            temp+=freq[i];
            ans = min(ans, temp);
        }
        return ans;
    }
};