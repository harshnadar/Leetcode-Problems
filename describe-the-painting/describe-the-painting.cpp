class Solution {
public:
    vector<vector<long long>> splitPainting(vector<vector<int>>& seg) {
        int n= seg.size();
        map<int, long long int> mp;
        for(auto it: seg){
            mp[it[0]]+=it[2];
            mp[it[1]]-=it[2];
        }
        long long int prev=0, color=0;
        vector<vector<long long int> > v;
        for(auto it: mp){
            if(mp[prev]>0){
                v.push_back({prev, it.first, mp[prev]});
            }
            mp[it.first]+=mp[prev];
            prev=it.first;
            // cout<<it.first<<" "<<it.second<<"\n";
        }
        return v;
    }
};