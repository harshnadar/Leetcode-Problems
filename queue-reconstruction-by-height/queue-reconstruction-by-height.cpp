class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        int n=people.size();
        sort(people.begin(), people.end());
        vector<vector<int> > v(n,vector<int> (2,-1));
        for(int i=0;i<n;i++){
            int count=people[i][1];
            for(int j=0;j<n;j++){
                if(v[j][0]==-1 && count==0){
                    v[j][0]=people[i][0];
                    v[j][1]=people[i][1];
                    break;
                }
                else if(v[j][0]==-1 || people[i][0]<=v[j][0]) count--;
            }
        }
        return v;
    }
};