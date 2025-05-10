class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> v;
        for(auto it: intervals){
            v.push_back({it[0], -1});
            v.push_back({it[1], 1});
        }
        v.push_back({newInterval[0], -1});
        v.push_back({newInterval[1], 1});
        sort(v.begin(), v.end());

        vector<vector<int> > ans;
        vector<int> temp;
        int count = 0;
        for(auto it: v){
            if(it[1] == 1){
                if(count==1){
                    temp.push_back(it[0]);
                    ans.push_back(temp);
                    temp.clear();
                }
                count--;
            }
            else{
                if(count == 0){
                    temp.push_back(it[0]);
                }
                count++;
            }
        } 
        return ans;

    }
};