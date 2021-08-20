class Solution {
public:
    int calculate(string s) {
        stack<int> st;
        int n=s.size();
        int sign = 1;
        int sum=0;
        
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch>='0' && ch<='9'){
                int val=0;
                while(i<n && s[i]>='0' && s[i]<='9'){
                    val = val*10 + (s[i]-'0');
                    i++;
                }
                i--;
                sum+=val*sign;
                sign=1;
            }
            else if(ch=='('){
                st.push(sum);
                st.push(sign);
                sign=1;
                sum=0;
            }
            else if(ch==')'){
                sum*=st.top();
                st.pop();
                sum+=st.top();
                st.pop();
            }
            else if(ch=='-'){
                sign*=-1;
            }
        }
        return sum;
    }
};