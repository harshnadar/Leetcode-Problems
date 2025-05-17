class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        int n = security.size();
        vector<bool> pref(n,false), suf(n, false);
        int count = 1;
        if(count > time) pref[0] = true;
        for(int i=1;i<n;i++){
            if(security[i-1] >= security[i]){
                count++;
            }
            else{
                count = 1;
            }
            if(count > time) pref[i] = true;
        }
        count = 1;
        if(count > time) suf[n-1] = true;
        for(int i = n-2;i>=0;i--){
            if(security[i] <= security[i+1]) count++;
            else count = 1;
            if(count > time) suf[i] = true;
        }
        vector<int> ans;
        for(int i = time;i<=n-time-1;i++){
            if(pref[i] && suf[i]) ans.push_back(i);
        }
        return ans;


    }
};