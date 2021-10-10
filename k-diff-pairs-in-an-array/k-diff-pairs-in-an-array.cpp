class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        int n=nums.size();
        map<int, int> mp;
        int ans=0;
        map<pair<int, int>, int> vis;

        for(int i=0;i<n;i++){
            int x = min(nums[i], nums[i]-k);
            int y = max(nums[i], nums[i]-k);
            if(vis.find({x,y})==vis.end() && mp[nums[i]-k]>0){
                ans+=mp[nums[i]-k];
                vis[{x,y}]=1;
                
                // cout<<nums[i]<<" "<<nums[i]-k<<endl;
            }
            
            x = min(nums[i], nums[i]+k);
            y = max(nums[i], nums[i]+k);
            if(vis.find({x,y})==vis.end() && mp[nums[i]+k]>0){
                ans+=mp[nums[i]+k];
                vis[{x,y}]=1;
                
                // cout<<nums[i]<<" "<<nums[i]+k<<endl;
            }

            mp[nums[i]]=1;
        }

        return ans;
    }
};