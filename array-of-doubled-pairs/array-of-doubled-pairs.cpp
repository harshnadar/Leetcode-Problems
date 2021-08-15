class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        int n=arr.size();
        // multiset<int> s;
        vector<int> v;
        map<int, int> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            // s.insert(abs(arr[i]));
        }
        for(auto it: mp){
            v.push_back(it.first);
        }
        sort(v.begin(), v.end(), [](int i, int j){return abs(i)<abs(j);});
        for(auto x: v){
            if(mp[x]>mp[2*x]) return false;
            mp[2*x]-=mp[x];
        }
        return true;
    }
};