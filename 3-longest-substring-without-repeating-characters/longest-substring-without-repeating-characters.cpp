class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int i=0, j=0;
        int n = s.size();
        map<char, int> mp;
        while(j<n && i<n && i<=j){
            mp[s[j]]++;
            cout<<s[j]<<" "<<j<<" "<<i<<" "<<mp[s[j]]<<endl;
            if(mp[s[j]]>1){
                while(mp[s[j]]>1){
                    mp[s[i]]--;
                    i++;
                }
            }
            ans = max(ans, j-i+1);
            j++;
        }

        return ans;
    }
};