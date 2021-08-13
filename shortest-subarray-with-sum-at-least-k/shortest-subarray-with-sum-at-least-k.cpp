class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<int> q;
        int res=n+1;
        for(int i=0;i<n;i++){
            if(i>0){
                nums[i]+=nums[i-1];
            }
            if(nums[i]>=k) res=min(res,i+1);
            while(q.size() && nums[i]-nums[q.front()]>=k){
                res=min(res, i-q.front());
                q.pop_front();
            }
            while(q.size() && nums[i]<=nums[q.back()]){
                q.pop_back();
            }
            q.push_back(i);
        }
        return ((res<=n)?res:-1);
    }
};