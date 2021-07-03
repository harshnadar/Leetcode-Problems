class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        int lb= lower_bound(arr.begin(),arr.end(),x)-arr.begin();
        int i=lb-1, j=lb;
        vector<int> v;
        // cout<<lb<<"\n";
        while(k){
            if(i>=0 && j<n && abs(arr[i]-x) <= abs(arr[j]-x)){
                v.push_back(arr[i]);
                i--;
            }
            else if(i>=0 && j<n && abs(arr[i]-x) > abs(arr[j]-x)){
                v.push_back(arr[j]);
                j++;
            }
            else if(i<0){
                v.push_back(arr[j]);
                j++;
            }
            else if(j>=n){
                v.push_back(arr[i]);
                i--;
            }
            k--;
        }
        sort(v.begin(),v.end());
        return v;
        
    }
};