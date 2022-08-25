class Solution {
public:
    string largestPalindromic(string num) {
        int n = num.size();
        map<char, int> mp;
        for(auto it: num){
            mp[it]++;
        }
        int x = -1;
        for(int i='9';i>='0';i--){
            if(mp[i]%2 && x==-1){
                x = i-'0';
            }
            mp[i]/=2;
        }
        bool flag = true;
        for(char i='1';i<='9';i++){
            if(mp[i]) flag = false;
        }
        if(flag){
            if(mp['0']){
                if(x!=-1) return to_string(x);
                else return "0";
            }
        }
        string ans;
        for(char i='9';i>='0';i--){
            ans+=string(mp[i],i);
        }
        if(x!=-1){
            ans+=(x+'0');
        }
        for(char i='0';i<='9';i++){
            ans+=string(mp[i],i);
        }
        return ans;
    }
};