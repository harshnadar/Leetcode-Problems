class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int count=0;
        for(char ch: s){
            if(ch=='('){
                st.push(ch);
            }
            else{
                if(st.empty()) count++;
                else st.pop();
            }
        }
        return st.size()+count;
    }
};