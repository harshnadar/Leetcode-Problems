class Solution {
public:
    const int mod=1e9+7;
    vector<long long int> pref;
    void maxSoFarSum(vector<int>& a){
        long long int max_so_far = INT_MIN;
        long long int max_ending_here = 0;
        
        int n=a.size();
        for(int i=0;i<n;i++){
            max_ending_here = max_ending_here + a[i];
            if(max_so_far < max_ending_here){
                max_so_far =max_ending_here;
            }
            if(max_ending_here <0){
                max_ending_here =0;
            }
            pref[i]=max_ending_here;
        }
        // return max_ending_here;
    }
    
    long long int maxEndingSum(vector<int>& a){
        long long int max_so_far = INT_MIN;
        long long int max_ending_here = 0;
        
        int n=a.size();
        for(int i=0;i<n;i++){
            max_ending_here = max_ending_here + a[i];
            if(max_so_far < max_ending_here){
                max_so_far =max_ending_here;
            }
            if(max_ending_here <0){
                max_ending_here =0;
            }
        }
        return max_so_far;
    }
    
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        vector<int> v;
        int n=arr.size();
        pref.resize(n);
        if(k==1) return maxEndingSum(arr);
        vector<long long int> prefSum(n,0);
        prefSum[0]=arr[0];
        for(int i=1;i<n;i++){
            prefSum[i]=prefSum[i-1]+arr[i];
        }
        
        long long int ans=0;
        long long int res=0;
        maxSoFarSum(arr);
        for(int i=0;i<n;i++){
            cout<<pref[i]<<" ";
        }
        if(k>1){
            res+=pref[n-1];
            res+=prefSum[n-1]*(k-2);
            res+= (*max_element(prefSum.begin(), prefSum.end()));
        }
        ans = max(res,ans);
        
        ans = max(ans, maxEndingSum(arr));
        
        v=arr;
        
        for(auto it: arr){
            v.push_back(it);
        }
        
        ans = max(ans, maxEndingSum(v));
        
        return ans%mod;
    }
};