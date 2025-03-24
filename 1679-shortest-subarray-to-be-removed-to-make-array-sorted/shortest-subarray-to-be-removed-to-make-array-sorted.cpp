class Solution {
public:
    int count = 0;
    vector<bool> pre_check;
    vector<bool> suf_check;

    void precompute(vector<int>& nums){
        int n = nums.size();
        pre_check.resize(n, false);
        suf_check.resize(n, false);
        int pre = -1, suf = 1e9+2;
        bool pre_flag = false, suf_flag = false;

        for(int i=0;i<n;i++){
            if(nums[i] >= pre && !pre_flag){
                pre_check[i] = true;
                pre = nums[i];
                count++;
            }
            else pre_flag = true;
            if(nums[n-i-1] <= suf && !suf_flag){
                suf_check[n-i-1]=true;
                suf = nums[n-i-1];
                count++;
            }
            else suf_flag = true;
            if(pre_flag && suf_flag) break;
        }
    }

    bool check(vector<int>& nums, int k){
        int n = nums.size();
        if(pre_check[k-1]) return true;
        if(suf_check[n-k]) return true;
        for(int i=0;i<k;i++){
            if(n-k+i+1 >=n) continue;
            if((nums[i]<=nums[n-(k-i)+1]) && (pre_check[i] && suf_check[n-(k-i)+1])) return true;
        }
        return false;
    }
    int findLengthOfShortestSubarray(vector<int>& nums) {
        int n = nums.size();
        precompute(nums);
        
        int lo = 1, hi = min(count,n);
        int k = 0;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(nums, mid)) lo = mid+1, k = mid;
            else hi = mid-1;
        }
        return n-k;

    }
};