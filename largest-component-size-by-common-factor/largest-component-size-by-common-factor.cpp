class Solution {
public:
    int sz[100004], par[100004];
    
    int find(int a){
        if(par[a]==a) return a;
        return par[a]=find(par[a]);
    }
    
    void uni(int a, int b){
        a=find(a);
        b=find(b);
        if(a==b) return;
        par[a]=b;
        sz[b]+=sz[a];
    }
    
    int largestComponentSize(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        for(int i=1;i<mx+1;i++){
            sz[i]=1;
            par[i]=i;
        }
        // cout<<find(2)<<endl;
        // uni(2,4);
        // cout<<sz[4]<<endl;
        // return 1;
        unordered_map<int, int> mp;
        for(auto x: nums){
            if(mp[x]) uni(mp[x],x);
            else{
                mp[x]=x;
            }
            for(int j=2;j*j<=x;j++){
                if(x%j) continue;
                int k = x/j;
                if(mp[j]) uni(mp[j],x);
                else mp[j]=x;
                if(mp[k]) uni(mp[k],x);
                else mp[k]=x;
            }
            
        }
        int ans =0;
        for(int i=1;i<mx+1;i++){
            ans = max(ans, sz[i]);
        }
        return ans;
    }
};