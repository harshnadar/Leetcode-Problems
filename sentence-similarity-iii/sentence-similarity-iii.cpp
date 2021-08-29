class Solution {
public:
    bool areSentencesSimilar(string s1, string s2) {
        vector<string> v1, v2;
        string s;
        s1+=" ";
        s2+=" ";
        for(int i=0;i<s1.size();i++){
            if(s1[i]==' '){
                v1.push_back(s);
                s="";
            }
            else s+=s1[i];
        }
        s="";
        for(int i=0;i<s2.size();i++){
            if(s2[i]==' '){
                v2.push_back(s);
                s="";
            }
            else s+=s2[i];
        }
        int n=v1.size();
        int m=v2.size();
        
        if(n==m){
            for(int i=0;i<n;i++){
                if(v1[i]!=v2[i]) return false;
            }
            return true;
        }
        
        if(n<m) {
            swap(n,m);
            swap(v1,v2);
        }
        
        for(auto it: v1) cout<<it<<" ";
        cout<<endl;
        for(auto it: v2) cout<<it<<' ';
        cout<<endl;
        
        int l=1;
        for(int i=0;i<m;i++){
            if(v1[i]==v2[i]) continue;
            else l=0;
        }
        if(l) {cout<<2<<endl; return true;}
        l=1;
        for(int j=n-m;j<n;j++){
            if(v1[j]==v2[j-n+m]) continue;
            else l=0;
        }
        if(l) {cout<<1<<endl; return true;}
        int j=0;
        bool count=false;
        for(int i=0;i<n+1;i++){
            if(j<m && i<n && v1[i]==v2[j]){
                j++; continue;
            }
            break;
        }
        int x=0;
        for(int i=n-1;i>=0;i--){
            if(v1[i]==v2[m-1-x]){
                x++; continue;
            }
            break;
        }
        // if(j==)
        return (j+x)==m;
    }
};