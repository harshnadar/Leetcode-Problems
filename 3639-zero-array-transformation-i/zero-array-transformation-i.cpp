class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> freq(n+1,0);
        for(auto it: queries){
            freq[it[0]]++;
            freq[it[1]+1]--;
        }
        int temp = 0;
        for(int i=0;i<n;i++){
            temp+=freq[i];
            if(temp<nums[i]) return false;
        }
        return true;
    }
};