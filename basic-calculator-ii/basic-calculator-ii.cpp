class Solution {
public:
    stack<long long int> st;
    
    void update(char ch,long long int num){
        if(ch=='+'){
            st.push(num);
        }
        else if(ch=='-'){
            st.push(-num);
        }
        else if(ch=='*'){
            int x=st.top();
            st.pop();
            st.push(x*num);
        }
        else if(ch=='/'){
            int x = st.top();
            st.pop();
            st.push(x/num);
        }
    }
    
    int cal(string s){
        int sign='+';
        long long int val=0;
        
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]>='0' && s[i]<='9'){
                val=val*10 + s[i]-'0';
            }
            else if(s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/'){
                update(sign,val);
                val = 0;
                sign = s[i];
            }
            // else if(s[i]=='('){
            //     val=  calculate(s.substr(i+1));
            //     i--;
            // }
            // else if(s[i]==')'){
            //     update(sign, val);
            //     int sm=0;
            //     while(st.size()){
            //         sm+=st.top();
            //         st.pop();
            //     }
            //     return sm;
            // }
        }
        update(sign, val);
        long long int sum=0;
        // stack<int> stCopy
        while(st.size()){
            sum+=st.top();
            st.pop();
        }
        return sum;
    }
    int calculate(string s) {
        
        return cal(s);
    }
};