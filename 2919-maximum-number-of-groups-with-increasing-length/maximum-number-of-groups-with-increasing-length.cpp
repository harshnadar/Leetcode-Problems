class Solution {
public:

    bool check(vector<int> usage, int k){
        int n = usage.size();
        int h = k;
        int gap = 0;
        for(int i=0;i<n;i++){
            gap = max(h-usage[i] + gap, 0);
            if(h) h-=1;
        }
        return gap==0;
    }
    int maxIncreasingGroups(vector<int>& usage) {
        sort(usage.begin(), usage.end(), greater<int>());
        int n = usage.size();
        int lo = 1, hi = n;
        int ans = 1;
        int a = check(usage, 12);
        // cout<<endl<<a;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            cout<<mid<<endl;
            
            if(check(usage, mid)) {lo = mid+1; ans = mid;}
            else hi = mid-1;
            cout<<endl;
        }
        return ans;
    }
};