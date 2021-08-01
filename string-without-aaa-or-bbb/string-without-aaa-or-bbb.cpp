class Solution {
public:
    string solve(int a, int b){
        int n= (a+1)/2;
        string s[n];
        int j=0;
        for(int i=0;i<n;i++){
            if(a-j>=2) s[i]+="11", j+=2;
            else s[i]+="1", j++;
        }
        int i=0;
        while(b>0){
            s[i%n]+="2";
            i++;
            b--;
        }
        string ans;
        for(int i=0;i<n;i++) ans+=s[i];
        return ans;
    }
    
    string strWithout3a3b(int a, int b) {
        string s, ans;
        // s=solve(4,1);
        // return s;
        if(a>=b){
            s=solve(a,b);
            cout<<s<<"1\n";
            for(int i=0;i<s.size();i++){
                if(s[i]=='1') ans+="a";
                else ans+="b";
            }
        }
        else{
            s=solve(b,a);
            cout<<s<<"2\n";
            for(int i=0;i<s.size();i++){
                if(s[i]=='1') ans+="b";
                else ans+="a";
            }
        } 
        return ans;
    }
};