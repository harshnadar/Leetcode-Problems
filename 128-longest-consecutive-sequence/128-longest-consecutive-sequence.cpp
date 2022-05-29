class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(), nums.end());
        set<int> a(nums.begin(), nums.end());
        vector<int> v;
        
        for(auto it: a) v.push_back(it);
        int n = v.size();
        int l=0, r=0;
        
        int ans = 0;
        while(r<n+1){
            if(r<n && v[r]-v[l] == r-l){ r++; continue;}
            else{
                ans = max(ans,r-l);
                l=r;
                r++;
            }
        }
        return ans;
    }
};