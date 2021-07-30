class Solution {
public:
    string smallestSubsequence(string s) {
//         int n=s.size();
//         int used[26]={}, cnt[26]={};
//         for(char ch:s) cnt[ch-'a']++;
//         string res;
//         for(char ch: s){
//             ++cnt[ch-'a'];
//             if(used[ch-'a']++ >0) continue;
//             while(!res.empty() && res.back()>ch && cnt[res.back()-'a']>0){
//                 used[res.back()-'a']=0;
//                 res.pop_back();
//             }
//             res.push_back(ch);
//         }
//         return res;
        
        int n=s.size();
        string res;
      int cnt[26] = {}, used[26] = {};
      for (auto ch : s) ++cnt[ch - 'a'];
      for (auto ch : s) {
        --cnt[ch - 'a'];
        if (used[ch - 'a']++ > 0) continue;
        while (!res.empty() && res.back() > ch && cnt[res.back() - 'a'] > 0) {
          used[res.back() - 'a'] = 0;
          res.pop_back();
        }
        res.push_back(ch);
      }
      return res;
    
    }
};