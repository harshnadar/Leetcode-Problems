class Solution {
public:
    int n;
    
    void solve(set<vector<int> >& res, vector<int>& sub, vector<int>& nums, int idx){
        if(sub.size()>=2) res.insert(sub);
        
        for(int i = idx; i<n;i++){
            if(sub.size()==0 || nums[i]>=sub[sub.size()-1]){
                sub.push_back(nums[i]);
                solve(res, sub, nums, i+1);
                sub.pop_back();
            }
        }
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n=nums.size();
        vector<int> sub;
        set<vector<int> > res;
        solve(res, sub, nums,0);
        vector<vector<int> > result(res.begin(), res.end());
        return result;
    }
};