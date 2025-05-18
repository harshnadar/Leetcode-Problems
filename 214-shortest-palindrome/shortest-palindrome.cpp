class Solution {
public:
    // string expand_around_centre(string& s, int left, int right){
    //     while(left>=0 && right<s.size() && s[left] == s[right]){
    //         left --;
    //         right++;
    //     }
    //     if(left < 0) return s.substr(left+1, right-left-1);
    //     return "";
    // }

    // string shortestPalindrome(string s) {
    //     if(s.empty()) return "";
    //     string longest;
    //     // string s1 = expand_around_centre(s, 0, 0);
    //     // string s2 = expand_around_centre(s, 0, 1);
    //     // if(s1.size() > longest.size()){
    //     //     longest = s1;
    //     // }
    //     // if(s2.size() > longest.size()){
    //     //     longest = s2;
    //     // }
    //     for(int i=(s.size()+1)/2;i>=0;i--){
    //         string s1 = expand_around_centre(s,i, i);
    //         string s2 = expand_around_centre(s, i, i+1);
    //         if(s1.size() > longest.size()) longest = s1;
    //         if(s2.size() > longest.size()) longest = s2;
    //         if(longest.size() > 0) break;
    //     }
    //     cout<<longest<<endl;
    //     string ans;
    //     for(int i = s.size()-1;i>=longest.size();i--){
    //         ans+=s[i];
    //     }
    //     ans+=s;
    //     return ans;
    // }
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        string l = s + "#" + rev_s;
        vector<int> p(l.size(), 0);

        for (int i = 1; i < l.size(); i++) {
            int j = p[i - 1];
            while (j > 0 && l[i] != l[j]) {
                j = p[j - 1];
            }
            if (l[i] == l[j]) {
                j++;
            }
            p[i] = j;
        }

        // p.back() is the length of the longest palindromic prefix
        return rev_s.substr(0, s.size() - p.back()) + s;
    }
};