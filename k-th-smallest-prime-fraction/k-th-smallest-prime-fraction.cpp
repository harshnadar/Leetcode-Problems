class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        // sort(arr.begin(), arr.end());
        int n=arr.size();
        if(k==1){
            vector<int> v;
            v={1,arr[n-1]};
            return v;
        }
        vector<pair<double, pair<int, int> > > v;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                v.push_back({(double)arr[i]/arr[j], {i,j}});
            }
        }
        sort(v.begin(), v.end());
        
        // for(auto it: v){
        //     cout<<it.first<<" "<<it.second.first<<" "<<it.second.second<<"\n";
        // }
        
        pair<int, int> p = v[k-1].second;
        
        vector<int> ans = {arr[p.first], arr[p.second]};
        return ans;
        
    }
};