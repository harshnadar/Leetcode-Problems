class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int> > ans;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int target2 = target - nums[i] - nums[j];
                int left = j+1, right = n-1;
                while(left< right){
                    if(nums[left]+nums[right] < target2){
                        left++;
                    }
                    else if(nums[left]+nums[right] > target2){
                        right--;
                    }
                    else{
                        vector<int> v(4,0);
                        v[0] = nums[i];
                        v[1] = nums[j];
                        v[2] = nums[left];
                        v[3] = nums[right];
                        
                        cout<<v[0]<<" "<<v[1]<<" "<<v[2]<<" "<<v[3]<<endl;
                        
                        ans.push_back(v);
                        
                        while(left<right && nums[left] == v[2]) left++;
                        while(left<right && nums[right] == v[3]) right--;
                    }
                    
                }
                while(j+1<n && nums[j+1] == nums[j]) j++;
            }
            while(i+1<n && nums[i+1] == nums[i]) i++;
        }
        
        return ans;
    }
};