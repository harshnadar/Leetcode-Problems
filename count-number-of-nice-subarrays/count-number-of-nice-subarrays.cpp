class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v;
        map<int, int> prev;
        for(int i=0;i<n;i++){
            v.push_back(nums[i]%2);
        }
        int cur_sum=0, ans=0;
        for(int i=0;i<n;i++){
            cur_sum+=v[i];
            if(cur_sum==k){ans++;}
            if(prev.find(cur_sum-k)!=prev.end()){
                ans+=prev[cur_sum-k];
            }
            prev[cur_sum]++;
        }
        return ans;
    }
};