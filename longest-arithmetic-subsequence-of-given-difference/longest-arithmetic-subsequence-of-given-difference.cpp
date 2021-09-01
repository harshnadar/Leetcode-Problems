class Solution {
public:
    int longestSubsequence(vector<int>& arr, int d) {
        int n=arr.size();
        int dp[n+1];
        dp[0]=1;
        map<int, int> mp;
        mp[arr[0]]=0;
        for(int i=1;i<n;i++){
            if(mp.find(arr[i]-d)!=mp.end()){
                dp[i]=dp[mp[arr[i]-d]] +1;
            }
            else{
                dp[i]=1;
            }
            mp[arr[i]]=i;
        }
        return *max_element(dp, dp+n);
    }
};