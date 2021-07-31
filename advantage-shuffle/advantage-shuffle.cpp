class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        multiset<int> s(begin(nums1), end(nums1));
        vector<int> ans;
        for(int i=0;i<n;i++){
            auto x=s.upper_bound(nums2[i]);
            if(x==s.end()) x=s.begin();
            ans.push_back(*x);
            s.erase(x);
                        
        }
        // cout<<"\n";
        return ans;
    }
};