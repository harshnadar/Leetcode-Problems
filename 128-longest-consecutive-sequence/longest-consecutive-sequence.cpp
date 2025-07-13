class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        set<int> s(nums.begin(), nums.end());
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        int curr_num;
        bool flag = true;
        int i=0;
        while(i<n){
            flag = true;
            curr_num = nums[i];
            int temp = 0;
            while(s.find(curr_num)!=s.end()){
                curr_num+=1;
                temp++;
                ans = max(ans, temp);
                i++;
                flag = false;
            }
            if(flag) i++;
        }
        return ans;
    }
};