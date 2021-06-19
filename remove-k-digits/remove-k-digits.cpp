class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        stack<char> s;
        for(char it: num){
            while(s.size() && k && s.top()>it){
                s.pop();
                k--;
            }
            if(s.size() || it!='0') s.push(it);
        }
        while(s.size() && k){
            s.pop();
            k--;
        }
        if(s.empty()) return "0";
        while(!s.empty()){
            num[n-1]=s.top();
            s.pop();
            n--;
        }
        return num.substr(n);
    }
};