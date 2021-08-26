class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n= arr.size();
        vector<int> pref(n+1,1);
        vector<int> suf(n+1,1);
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                pref[i]+=pref[i-1];
            }
        }
        
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                suf[i]+=suf[i+1];
            }
        }
        
        int ans =0;
        for(int i=1;i<n;i++){
            if(pref[i]>1 && suf[i]>1)
            ans = max(ans, pref[i]+suf[i]-1);
        }
        return (ans>=3?ans:0);
    }
};