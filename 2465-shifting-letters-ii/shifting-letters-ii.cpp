class Solution {
public:
    char change(char a, int count){
        if(count>0) return (char)('a' + (a + count - 'a')%26);
        if(count<0) return (char)('a' + (a + (26*1000+count - 'a')%26)%26);
        return a;
    }
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> freq(n+1, 0);
        for(auto it: shifts){
            if(it[2] == 1){
                freq[it[0]]++;
                freq[it[1]+1]--;
            }
            else{
                freq[it[0]]--;
                freq[it[1]+1]++;
            }
        }
        int count = 0;
        string ans;
        for(int i=0;i<s.size(); i++){
            count+=freq[i];
            ans+=change(s[i], count);
        }
        return ans;
    }
};