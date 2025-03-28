class Solution {
public:
    map<char, string> mp = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };

    vector<string> ans;

    void solve(int i, string digits, string s){
        if(i==digits.size()){
            ans.push_back(s);
            return;
        }
        // for(int j = i;j<digits.size(); j++){
        //     for(char c : mp[digits[j]]){
        //         temp+=c;
        //         solve(j+1, digits, temp);
        //         temp.substr(0,temp.size()-1);
        //     }
        // }

        string temp = "";
        for(char c: mp[digits[i]]){
            solve(i+1, digits, s+c);
        }
    }


    vector<string> letterCombinations(string digits) {
        string s;
        if(digits.empty()) return ans;
        solve(0,digits,s);

        
        return ans;
    }
};