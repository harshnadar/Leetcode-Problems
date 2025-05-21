class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest_streak_count = 0;
        
        for(int num : numSet) {  // Iterate through unique numbers only
            if(numSet.find(num - 1) == numSet.end()) {  // Check if it's start of sequence
                int curr_num = num;
                int curr_streak = 1;
                
                while(numSet.find(curr_num + 1) != numSet.end()) {
                    curr_num++;
                    curr_streak++;
                }
                longest_streak_count = max(longest_streak_count, curr_streak);
            }
        }
        return longest_streak_count;
    }
};