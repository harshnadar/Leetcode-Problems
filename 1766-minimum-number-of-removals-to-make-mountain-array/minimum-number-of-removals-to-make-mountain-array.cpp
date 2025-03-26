class Solution {
public:
    int n;

    vector<int> getLIS(vector<int> nums){
        vector<int> lis;
        
        for(int i=0;i<n;i++){
            int x = nums[i];
            if(lis.empty() || lis[lis.size()-1] <x){
                lis.push_back(x);
                nums[i] = lis.size();
            }
            else{
                int idx = upper_bound(lis.begin(), lis.end(), x-1) - lis.begin();
                lis[idx] = x;
                nums[i] = idx+1;
            }
        }
        return nums;
    }
    int minimumMountainRemovals(vector<int>& nums) {
        n = nums.size();
        cout<<n<<endl;
        vector<int> left = getLIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int> right = getLIS(nums);
        reverse(right.begin(), right.end());

        for(auto it: left) cout<<it<<" ";
        cout<<endl;
        for(auto it: right) cout<<it<<" ";
        cout<<endl;
        int ans = 0;
        for(int i=0;i<n;i++){
            if(left[i] >=2 && right[i]>=2)
                ans = max(ans, left[i]+right[i]-1);
        }
        
        return n-ans;
    }
};