class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& ob) {
        int n=ob.size();
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(ans.empty() || ans[ans.size()-1]<=ob[i]){
                ans.push_back(ob[i]);
                ob[i]=ans.size();
            }
            else{
                int it= upper_bound(ans.begin(), ans.end(), ob[i]) - ans.begin();
                ans[it]=ob[i];
                ob[i]=it+1;
            }
        }
        return ob;
    }
};