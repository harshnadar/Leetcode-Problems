class Solution {
public:
    vector<int> set1, set2, nums;
    
    void solve(int start, int end, int sum, vector<int>& set){
        if(start>=end){
            set.push_back(sum);
            return;
        }
        
        solve(start+1, end, sum+nums[start], set);
        
        solve(start+1, end, sum, set);
    }
    
    int minAbsDifference(vector<int>& nums, int goal) {
        this->nums=nums;
        int n=nums.size();
        solve(0,n/2,0,set1);
        solve(n/2, n, 0, set2);
        
        sort(set2.begin(), set2.end());
        int result=INT_MAX;
        
        for(int i=0;i<set1.size();i++){
            auto it = upper_bound(set2.begin(), set2.end(), goal-set1[i]);
            if(it!=set2.end()){
                result=min(result, abs(goal - set1[i] - *(it)));
            }
            if(it!=set2.begin()){
                result = min(result, abs(goal - set1[i] - *(--it)));
            }
        }
        return result;
    }
};