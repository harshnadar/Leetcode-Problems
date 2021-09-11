class Solution {
public:
    
    int perm(int n,int m){
        return m==0?1:perm(n,m-1)*(n-m+1);
    }
    int numDupDigitsAtMostN(int N) {
        vector<int> dig;
        for(int i=N+1;i>0;i/=10){
            dig.push_back(i%10);
        }
        reverse(begin(dig), end(dig));
        
        int n=dig.size();
        
        int res=0;
        
        for(int i=1;i<n;i++){
            res+=9*perm(9,i-1);
        }
        
        set<int> seen;
        
        for(int i=0;i<n;i++){
            for(int j=((i==0)?1:0);j<dig[i];j++){
                if(seen.find(j)==seen.end()) res+=perm(9-i,n-i-1);
                // cout<<"HI"<<endl;
            }
            if(seen.find(dig[i])!=seen.end()) break;
            seen.insert(dig[i]);
        }
        
        return N-res;
    }
};