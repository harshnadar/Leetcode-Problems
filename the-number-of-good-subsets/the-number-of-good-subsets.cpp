const int mod= 1e9+7;

class Solution {
public: 
    int numberOfGoodSubsets(vector<int>& nums) {
        int n=nums.size();
        int prime[10] = {2,3,5,7,11,13,17,19,23,29};
        int ones = 0;
        long long int res = 0;
        
        map<int,int> mp;
        
        for(int x: nums){
            if(x%4==0 || x%9==0 || x%25==0) continue;
            if(x==1) ones++;
            else {mp[x]++;}
        }
        
        vector<long long int> dp(1<<10,0), tmp;
        dp[0]=1;
        for(auto x: mp){
            int cur_mask = 0;
            
            for(int i=0;i<10;i++){
                if((x.first)%prime[i]==0){
                    cur_mask+=(1<<i);
                } 
            }
            cout<<cur_mask<<endl;
            tmp.assign(1<<10,0);
            
            for(int mask=0;mask<(1<<10); mask++){
                if((cur_mask&mask) ==0){
                    tmp[(mask|cur_mask)] = (dp[mask]*((long long int)x.second))%mod;
                }
            }
            
            for(int i=0;i<(1<<10);i++){
                dp[i]= (dp[i]+tmp[i])%mod;
            }
        }
        
        for(int i=1;i<(1<<10);i++){
            res = (res+dp[i])%mod;
        }
        
        while(ones--){
            res = (res*(long long int)2)%mod;
        }
        
        return res;
    }
};