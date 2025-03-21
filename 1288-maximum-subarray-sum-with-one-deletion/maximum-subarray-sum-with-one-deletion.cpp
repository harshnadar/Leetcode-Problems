class Solution {
public:
    vector<int> kadanes(vector<int>& arr){
        int n = arr.size();
        vector<int> res;
        int curr_sum = 0;
        for(auto it: arr){
            curr_sum+=it;
            if(curr_sum<0){
                curr_sum = 0;
            }
            res.push_back(curr_sum);
        }
        return res;
    }
    int maximumSum(vector<int>& arr) {
        int n =arr.size();
        vector<int> prefix = kadanes(arr);
        for(auto it: prefix) cout<<it<<" ";
        cout<<endl;
        reverse(arr.begin(), arr.end());
        vector<int> suffix = kadanes(arr);
        reverse(arr.begin(), arr.end());
        reverse(suffix.begin(), suffix.end());
        int ans = *max_element(arr.begin(), arr.end());
        bool flag = true;
        for(auto it: arr){
            if(it>0) flag = false;
        }
        if(flag) return ans;
        for(int i=0;i<n;i++){
            int a = ((i+2)<n)?suffix[i+2]:0;
            ans = max({ans, prefix[i]+a,prefix[i], suffix[i], arr[i]});
        }
        return ans;
    }
};