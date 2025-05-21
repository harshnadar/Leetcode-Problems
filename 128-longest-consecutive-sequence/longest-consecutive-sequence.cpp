class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());
        int n = nums.size();
        int longest_streak_count = 0;

        for(auto& it: st){
            if(!st.count(it-1)){
                int curr_num = it;
                int curr_streak = 1;

                while(st.count(curr_num+1)){
                    curr_num++;
                    curr_streak++;
                }
                longest_streak_count = max(longest_streak_count, curr_streak);
            }
        }
        return longest_streak_count;
    }
};