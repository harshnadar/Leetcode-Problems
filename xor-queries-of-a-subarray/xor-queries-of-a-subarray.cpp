class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n=arr.size();
        int pref[n+2];
        pref[0]=arr[0];
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]^arr[i];
        }
        
        int q=queries.size();
        int i=0;
        vector<int> ans;
        while(q--){
            int l= queries[i][0];
            int r = queries[i][1];
            i++;
            if(l==0) ans.push_back(pref[r]);
            else ans.push_back(pref[r]^pref[l-1]);
        }
        return ans;
    }
};