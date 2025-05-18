class Solution {
public:
    string expand_around_centre(string& s, int left, int right){
        while(left>=0 && right<s.size() && s[left] == s[right]){
            left --;
            right++;
        }
        return s.substr(left+1, right-left-1);
    }

    string longestPalindrome(string s) {
        if(s.empty()) return "";
        string longest;
        for(int i=0;i<s.size();i++){
            string s1 = expand_around_centre(s,i, i);
            string s2 = expand_around_centre(s, i, i+1);
            if(s1.size() > longest.size()) longest = s1;
            if(s2.size() > longest.size()) longest = s2;
        }
        return longest;
        
    }
};