class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int> > v;
        
        for(auto it: intervals){
            v.push_back({it[0],-1});
            v.push_back({it[1],1});
        }
        
        sort(v.begin(), v.end());
        int n=v.size();
        
        int i=0;
        int x=1e9;
        int y=0;
        vector<vector<int> > ans;
        int sum=0;
        while(i<n){
            sum+=v[i][1];
            if(sum==0){
                y=max(y,v[i][0]);
                ans.push_back({x,y});
                i++;
                x=1e9;
                continue;
            }
            else{
                x=min(x,v[i][0]);
                i++;
                continue;
            }
        }
        
        return ans;
    }
};