class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        vector<int> cost(26, 1e4);
        for(int i = 0;i<chars.size();i++){
            cost[chars[i]-'a'] = vals[i]; 
        }
        for(int i=0;i<26;i++){
            if(cost[i] == 1e4) cost[i] = i+1;
        }

        vector<int> v;
        for(auto c: s){
            v.push_back(cost[c-'a']);
        }

        int max_sum = 0;
        int curr_sum = 0;
        for(auto it: v){
            curr_sum+=it;
            if(curr_sum<0){
                curr_sum = 0;
            }
            max_sum = max(curr_sum, max_sum);
        }
        return max_sum;
    }
};