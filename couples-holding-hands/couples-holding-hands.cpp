class Solution {
public:
    int par[101];
    
    int find(int a){
        if(par[a]==a) return a;
        return par[a]=find(par[a]);
    }
    
    bool uni(int a, int b){
        a=find(a);
        b=find(b);
        if(a==b) return false;
        par[b]=a;
        return true;
    }
    
    int minSwapsCouples(vector<int>& row) {
        int n=row.size();
        for(int i=0;i<n-1;i+=2){
            par[row[i]]=row[i];
            par[row[i+1]]=row[i];
        }
        int ans=0;
        for(int i=1;i<n;i+=2){
            if(uni(i,i-1)){
                ans++;
            }
        }
        return ans;
    }
};