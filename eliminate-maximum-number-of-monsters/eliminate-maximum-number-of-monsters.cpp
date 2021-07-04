class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        int n=dist.size();
        int ans=0,t=0;
        multiset<double> s;
        for(int i=0;i<n;i++){
            s.insert((dist[i]*1.0)/speed[i]);
        }
        for(auto it:s){
            if(t>=it) break;
            else ans++,t++;
        }
        return ans;
    }
};