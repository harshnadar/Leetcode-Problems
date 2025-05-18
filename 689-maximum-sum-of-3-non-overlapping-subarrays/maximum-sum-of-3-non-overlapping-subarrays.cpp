class Solution {
public:
    vector<int> pref_max, suf_max;
    vector<int> prefill_pref(vector<int>& nums, int k){
        int n = nums.size();
        vector<int> pref(n-k+1,0);
        pref_max.resize(n-k+1, -1);
        suf_max.resize(n-k+1, -1);
        pref[0] = accumulate(nums.begin(), nums.begin() + k, 0);
        pref_max[0] = 0;
        for(int i = 1;i<=n-k;i++){
            pref[i] = pref[i-1] + nums[i+k-1] - nums[i-1];
            if(pref[i] > pref[pref_max[i-1]]){
                pref_max[i] = i;
            }
            else{
                pref_max[i] = pref_max[i-1];
            }
        }
        suf_max[n-k] = n-k;
        for(int i = n-k-1;i>=0;i--){
            if(pref[i] >= pref[suf_max[i+1]]){
                suf_max[i] = i;
            }
            else{
                suf_max[i] = suf_max[i+1];
            }
        }
        return pref;
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pref = prefill_pref(nums, k);
        for(auto it: pref) cout<<it<<" ";
        cout<<endl;
        for(auto it: pref_max) cout<<it<<" ";
        cout<<endl;
        for(auto it: suf_max) cout<<it<<" ";
        vector<int> ans;
        int curr_max = -1;

        for(int i=k;i<=n-2*k;i++){
            int sum1 = pref[i];
            int sum2 = pref[pref_max[i-k]];
            int sum3 = pref[suf_max[i+k]];

            if(curr_max < sum1 + sum2 + sum3){
                ans = {pref_max[i-k], i, suf_max[i+k]};
                curr_max = sum1+sum2+sum3;
            }
        }

        return ans;
    }
};