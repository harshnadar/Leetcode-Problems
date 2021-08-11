class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<char, string> mp;
        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
                
        if(digits.empty()) return vector<string>();
        vector<string> ans;
        ans.push_back("");
        for(char digit: digits){
            vector<string> tmp;
            for(char it: mp[digit]){
                for(string res: ans){
                    tmp.push_back(res+it);
                }
            }
            swap(ans, tmp);
        }
        return ans;
    }
};