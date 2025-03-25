class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        map<char, int> odd, even;

        for(int i=0;i<n;i+=2){
            odd[s1[i]]++;
            odd[s2[i]]--;
            even[s1[i+1]]++;
            even[s2[i+1]]--;
        }

        for(char i='a';i<='z';i++){
            if(odd[i] || even[i]) return false;
        }
        return true;
    }
};