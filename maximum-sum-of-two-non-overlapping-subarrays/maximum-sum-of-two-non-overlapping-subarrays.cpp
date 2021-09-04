class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int se) {
        int n=nums.size();
        int pref[n+1];
        pref[0]=0;
        for(int i=0;i<n;i++){
            pref[i+1] = pref[i]+nums[i];
        }
        int ans= 0;
        for(int i=0;i+f<=n;i++){
            int f_sum = pref[i+f]-pref[i];
            cout<<f_sum<<" ";
            for(int j=0;j+se<=i;j++){
                int s_sum = pref[j+se]-pref[j];
                cout<<s_sum<<" ";
                ans = max(s_sum+f_sum, ans);
            }
            cout<<endl;
            for(int j=i+f;j+se<=n;j++){
                int s_sum=pref[j+se]-pref[j];
                ans = max(s_sum+f_sum,ans);
            }
        }
        return ans;
    }
};