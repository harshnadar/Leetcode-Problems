class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int> > v;
        for(auto it: intervals){
            v.push_back({it[0], -1});
            v.push_back({it[1], 1});
        }
        sort(v.begin(), v.end());
        stack<int> s;
        vector<vector<int> > ans;
        vector<int> temp;
        for(auto it: v){
            if(it[1] == 1){
                if(s.size() == 1){
                    temp.push_back(it[0]);
                    ans.push_back(temp);
                    temp.clear();
                }
                s.pop();
            }
            else{
                if(s.empty()){
                    temp.push_back(it[0]);
                }
                s.push(it[0]);
            }
        }
        return ans;
    }
};