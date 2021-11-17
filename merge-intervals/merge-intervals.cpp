class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if(n==1) return intervals;
        vector<vector<int> > v;
        
        for(auto it: intervals){
            v.push_back({it[0],-1});
            v.push_back({it[1], 1});
        }
        
        sort(v.begin(), v.end());
        int sum=-1;
        vector<vector<int> > ans;
        int first, second;
        first = v[0][0];
        bool flag = true;
        for(int i=1;i<(int)v.size();i++){
            sum+=v[i][1];
            if(sum==0){
                second = v[i][0];
                flag = false;
                
                ans.push_back({first,second});
                first = 0;
                second=0;
                continue;
            }
            if(sum==-1 && flag==false){
                first = v[i][0];
                flag = true;
            }
        }
        
        return ans;
        
    }
};