class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int target) {
        vector<int> t= times[target];
        sort(times.begin(), times.end());
        int n=times.size();
        vector<int> emp(n);
        for(auto it: times){
            for(int i=0;i<n;i++){
                if(emp[i]<=it[0]){
                    emp[i]=it[1];
                    if(it==t) return i;
                    else break;
                }
            }
        }
        return 1;
    }
};